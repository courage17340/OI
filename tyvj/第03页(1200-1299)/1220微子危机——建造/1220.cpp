#include <cstdio>
#include <algorithm>
struct rec{int x,y,k;};
rec a[200010];
int f[200010],n,ans;
bool v[200010] = {0};
bool cmp1(rec a,rec b){
	return a.x < b.x;
}
bool cmp2(rec a,rec b){
	return a.y < b.y;
}
int father(int x){
	if (f[x] == x) return x;
	f[x] = father(f[x]);
	return f[x];
}
int main(){
	scanf("%d%d%d",&n,&n,&n);
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].k = i;
	}
	std::sort(a + 1,a + n + 1,cmp1);
	for (int i = 1;i < n;i++) if (a[i].x == a[i + 1].x)
		if (father(a[i].k) != father(a[i + 1].k)) f[father(a[i].k)] = father(a[i + 1].k);
	std::sort(a + 1,a + n + 1,cmp2);
	for (int i = 1;i < n;i++) if (a[i].y == a[i + 1].y)
		if (father(a[i].k) != father(a[i + 1].k)) f[father(a[i].k)] = father(a[i + 1].k);
	for (int i = 1;i <= n;i++) v[father(i)] = 1;
	ans = -1;
	for (int i = 1;i <= n;i++) ans += v[i];
	printf("%d\n",ans);
}
