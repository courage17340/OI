#include <cstdio>
#include <algorithm>
int f[310],n,m,ans;
struct rec{int x,y,c;};
rec a[10010];
bool cmp(rec a,rec b){
	return a.c < b.c;
}
int father(int x){
	if (f[x] == x) return x;
	f[x] = father(f[x]);
	return f[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
	std::sort(a + 1,a + m + 1,cmp);
	for (int i = 1;i <= m;i++) if (father(a[i].x) != father(a[i].y)){
		f[f[a[i].x]] = f[a[i].y];
		ans = a[i].c;
	}
	printf("%d %d",n - 1,ans);
}
