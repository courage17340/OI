#include <cstdio>
typedef long long ll;
ll n,m,p;
int f[70],k;
ll mul(ll a,ll b){
	ll ans = 0;
	while (b){
		if (b & 1) ans = (ans + a) % p;
		a = (a << 1) % p;
		b >>= 1;
	}
	return ans;
}
ll pow(ll a,ll n){
	ll ans = 1;
	k = 0;
	while (n){
		f[++k] = n & 1;
		n >>= 1;
	}
	for (int i = k;i >= 1;i--){
		ans = mul(ans,ans);
		if (f[i]) ans = mul(ans,a);
	}
	return ans;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	printf("%lld",mul(m,pow(m - 1,n - 1)));
}
