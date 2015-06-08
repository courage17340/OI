#include <cstdio>
#include <algorithm>
struct rec{int x,y,z;};
rec a[200010];
bool cmp(rec a,rec b){
	return a.z < b.z;	
}
int n;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;++i){
		scanf("%d",&a[i].x);
		a[i].y = i;
		a[i].z = a[i].x + a[i].y;
	}
	std::sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i < n;++i) if (a[i].z == a[i + 1].z){
		printf(":(\n");
		return 0;
	}
	for (int i = 1;i < n;++i) printf("%d ",a[i].x + a[i].y - i);
	printf("%d\n",a[n].x + a[n].y - n);
}
