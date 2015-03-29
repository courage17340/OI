#include <cstdio>
int f[200010] = {0},a[200010] = {0},n,m,k,p,q,ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	k = 0;
	p = 0;
	while (k < m && p < n){
		p++;
		if (f[a[p]] == 0) k++;
		f[a[p]]++;
	}
	if (k < m){
		printf("NO\n");
		return 0;
	}
	ans = n;
	q = 1;
	while (p <= n){
		while (f[a[q]] > 1) f[a[q++]]--;
		if (ans > p - q + 1) ans = p - q + 1;
		f[a[++p]]++;
	}
	printf("%d\n",ans);
}
