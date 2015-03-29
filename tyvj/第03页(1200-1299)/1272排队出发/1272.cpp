#include <cstdio>
#include <algorithm>
struct rec{int x,y,z;};
rec a[50010];
bool cmp(rec a,rec b){
	return a.z < b.z;
}
int max(int a,int b){
	return a > b ? a : b;
}
int n,ans,x;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].z = a[i].x + a[i].y;
	}
	std::sort(a + 1,a + n + 1,cmp);
	ans = -a[1].y;
	x = 0;
	for (int i = 2;i <= n;i++){
		x += a[i - 1].x;
		ans = max(ans,x - a[i].y);
	}
	printf("%d",ans);
}
