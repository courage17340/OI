#include <cstdio>
long long n,ans = 0,a[1000];
int p = 0;
int phi(long long x){
	if (x == 1) return 1;
	long long k = x;
	for (int i = 2;i * i <= x;i++) if (x % i == 0){
		while (x % i == 0) x /= i;
		k = k - k / i;
	}
	if (x > 1) k = k - k / x;
	return k;
}
int main(){
	while (scanf("%I64d",&n) != EOF){
		p = ans = 0;
		for (int i = 1;i * i <= n;i++) if (n % i == 0) a[++p] = i;
		if (a[p] * a[p] != n){
			for (int i = p + 1;i <= p * 2;i++) a[i] = n / a[p * 2 - i + 1];
			p *= 2;
		}else{
			for (int i = p + 1;i < p * 2;i++) a[i] = n / a[p * 2 - i];
			p = p * 2 - 1;
		}
		for (int i = 1;i <= p;i++) ans += a[i] * phi(n / a[i]);
		printf("%I64d\n",ans);
	}
}