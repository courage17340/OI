#include <cstdio>
#include <algorithm>
struct rec{int x,y;};
rec a[2010];
int f[2010],n,ans = 0;
void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}
int max(int a,int b){
	return a > b ? a : b;
}
bool cmp(rec a,rec b){
	return a.x < b.x;
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		if (a[i].x < a[i].y) swap(a[i].x,a[i].y);
	}
	std::sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++) f[i] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 1;j < i;j++) if (a[i].x > a[j].x && a[i].y > a[j].y) f[i] = max(f[i],f[j] + 1);
	ans = 1;
	for (int i = 2;i <= n;i++) ans = max(ans,f[i]);
	printf("%d",ans);
}
