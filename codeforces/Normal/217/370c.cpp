#include <cstdio>
#include <algorithm>
int n,m,a[5010],b[5010],c[110]={0},k,p,ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	std::sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++) c[a[i]]++;
	p = 1;
	for (int i = 2;i <= m;i++) if (c[i] > c[p]) p = i;
	k = n;
	while (a[k] != p) k--;
	p = k;
	while (p > 1 && a[p - 1] == a[k]) p--;
	p--;
	for (int i = 1;i <= n;i++){
		k++;
		p++;
		if (k > n) k = 1;
		if (p > n) p = 1;
		b[k] = a[p];
	}
	ans = 0;
	for (int i = 1;i <= n;i++) if (a[i] != b[i]) ans++;
	printf("%d\n",ans);
	for (int i = 1;i <= n;i++) printf("%d %d\n",a[i],b[i]);
}
