#include <cstdio>
#include <cmath>
typedef long long ll;
int n,k;
ll ans;
int rlimit(int k,int l){
    return k / (k / l);
}
//k % i == k - k / i * i
ll calc(int k,int n){
    ll ret = (ll)k * n;
    int sq = sqrt(k);
    for (int i = 1;i <= sq && i <= n;i++) ret -= k / i * i;
    if (sq >= n) return ret;
    int l = sq + 1,r;
    while (l <= n){
        r = rlimit(k,l);
        if (r > n) r = n;
        ret -= (ll)k / l * (l + r) * (r - l + 1) / 2;
        l = r + 1;
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&k);
    if (n >= k) ans = calc(k,k) + (ll)(n - k) * k;else ans = calc(k,n);
    printf("%lld\n",ans);
}
