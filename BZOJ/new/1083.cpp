#include <cstdio>
#include <algorithm>
struct road{int l,r,x;};
road a[10010];
int n,m,f[310],ans = 0;
bool cmp(road a,road b){return a.x < b.x;}
int father(int x){
	if (x == f[x]) return x;
	f[x] = father(f[x]);
	return f[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= m;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].x);
	std::sort(a + 1,a + m + 1,cmp);
	for (int i = 1;i <= m;i++) if (father(a[i].l) != father(a[i].r)){
		ans = a[i].x;
		f[father(a[i].l)] = father(a[i].r);
	}
	printf("%d %d\n",n - 1,ans);
}
