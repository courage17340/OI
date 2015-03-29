#include <cstdio>
#include <algorithm>
bool v[5010] = {0};
struct rec{int x,y,z;};
rec a[3010];
int n,m,p,x,ans = 0;
bool cmp(rec a,rec b){
	return a.y < b.y;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	std::sort(a + 1,a + m + 1,cmp);
	for (int i = 1;i <= m;i++){
		x = a[i].z;
		for (int j = a[i].x;j <= a[i].y;j++) x -= v[j];
		if (x < 0) x = 0;
		p = a[i].y;
		while (x){
			while (v[p]) p--;
			v[p] = 1;
			x--;
			ans++;
		}
	}
	printf("%d\n",ans);
}
