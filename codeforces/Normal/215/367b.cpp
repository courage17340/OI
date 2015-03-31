#include <cstdio>
#include <cstring>
#include <algorithm>
int n,m,p,a[200010],b[200010],c[200010]={0},d[200010],e[200010] = {0},l,r,ans[200010],k = 0;
bool g[200010]={0};
int f(int x){
	int l = 1,r = m,mid;
	if (x > b[m] || x < b[1]) return c[m] + 1;
	while (l < r){
		mid = (l + r) >> 1;
		if (x == b[mid]) return c[mid];
		if (x < b[mid]) r = mid - 1;
		if (x > b[mid]) l = mid + 1;
	}
	if (b[l] != x) return c[m] + 1;
	return c[l];
}
bool yes(){
	for (int i = 1;i <= c[m];i++) if (d[i] != e[i]) return 0;
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= m;i++) scanf("%d",&b[i]);
	std::sort(b + 1,b + m + 1);
	c[1] = 1;
	for (int i = 2;i <= m;i++){
		c[i] = c[i - 1];
		if (b[i] != b[i - 1]) c[i]++;
	}
	for (int i = 1;i <= n;i++) a[i] = f(a[i]);
	for (int i = 1;i <= m;i++) e[c[i]]++;
	for (int i = 1;i <= p;i++){
		l = i;
		r = i + (m - 1) * p;
		if ((long long)p * (m - 1) + i > n) continue;
		memset(d,0,sizeof(d));
		for (int j = l;j <= r;j += p) d[a[j]]++;
		if (yes()) g[l] = 1;
		while (r + p <= n){
			d[a[l]]--;
			d[a[r + p]]++;
			l += p;
			r += p;
			if (d[a[l - p]] != e[a[l - p]] || d[a[r]] != e[a[r]]) continue;
			if (a[l - p] == a[r]){
				g[l] = g[l - p];
				continue;
			}
			if (!yes()) continue;
			g[l] = 1;
		}
	}
	for (int i = 1;i <= n;i++) if (g[i]) ans[++k] = i;
	printf("%d\n",k);
	for (int i = 1;i < k;i++) printf("%d ",ans[i]);
	if (k) printf("%d\n",ans[k]);
}
