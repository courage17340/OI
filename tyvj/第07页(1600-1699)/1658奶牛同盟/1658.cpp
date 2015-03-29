#include <cstdio>
int n,p,x,k = 1;
bool f[10000010] = {0};
typedef long long ll;
ll ans = 1;
int main(){
	scanf("%d",&n);
	p = 2;
	while (p * p <= n){
		while (f[p]) p++;
		for (int i = p * 2;i <= n;i += p) f[i] = 1;
		p++;
	}
	for (int i = 2;i <= n;i++) if (!f[i]){
		k++;
		x = i;
		while ((ll)x * i <= n) x *= i;
		ans += x;
	}
	printf("%d %lld\n",k,ans);
}
