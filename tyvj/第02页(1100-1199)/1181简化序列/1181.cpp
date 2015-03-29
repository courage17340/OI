#include <cstdio>
int n,x,a[1000010],p;
long long ans;
int main(){
	scanf("%d",&n);
	ans = 0;
	p = 0;
	for (int i = 1;i <= n;i++){
		scanf("%d",&x);
		while (p && x > a[p]){
			if (p > 1 && a[p - 1] < x) ans += a[p - 1];else ans += x;
			p--;
		}
		a[++p] = x;
	}
	for (int i = p - 1;i >= 1;i--) ans += a[i];
	printf("%lld",ans);
}
