#include <cstdio>
#include <algorithm>
struct rec{int x,h;};
rec a[50010];
int n,d,ans,f[50010],p,q,y[50010]={0};
bool cmp(rec a,rec b){
	return a.x < b.x;
}
int main(){
	scanf("%d%d",&n,&d);
	for (int i = 1;i <= n;i++) scanf("%d%d",&a[i].x,&a[i].h);
	std::sort(a + 1,a + n + 1,cmp);
	p = q = 1;
	f[1] = 1;
	for (int i = 2;i < n;i++){
		while (p <= q && a[f[p]].x < a[i].x - d) p++;
		if (p <= q && a[f[p]].h >= 2 * a[i].h) y[i]--;
		while (p <= q && a[i].h >= a[f[q]].h) q--;
		f[++q] = i;
	}
	p = q = 1;
	f[1] = n;
	for (int i = n - 1;i >= 2;i--){
		while (p <= q && a[f[p]].x > a[i].x + d) p++;
		if (p <= q && a[f[p]].h >= 2 * a[i].h) y[i]--;
		while (p <= q && a[i].h >= a[f[q]].h) q--;
		f[++q] = i;
	}
	ans = 0;
	for (int i = 2;i < n;i++) if (y[i] == -2) ans++;
	printf("%d\n",ans);
}
