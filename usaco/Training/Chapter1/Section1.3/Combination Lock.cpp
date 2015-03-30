/*
USER: courage2
LANG: C++
TASK: combo
*/
#include <cstdio>
int n,a[3],b[3],ans = 0;
int min(int a,int b){
	return a < b ? a : b;
}
int Abs(int x){
	return x > 0 ? x : -x;
}
int dis(int x,int y){
	int ret = Abs(x - y);
	ret = min(ret,n - ret);
	return ret;
}
bool yes(int x,int y,int z){
	if (dis(x,a[0]) <= 2 && dis(y,a[1]) <= 2 && dis(z,a[2]) <= 2) return 1;
	if (dis(x,b[0]) <= 2 && dis(y,b[1]) <= 2 && dis(z,b[2]) <= 2) return 1;
	return 0;
}
int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0;i < 3;i++) scanf("%d",a + i);
	for (int i = 0;i < 3;i++) scanf("%d",b + i);
	for (int x = 1;x <= n;x++)
		for (int y = 1;y <= n;y++)
			for (int z = 1;z <= n;z++)
				if (yes(x,y,z)) ans++;
	printf("%d\n",ans);
}
