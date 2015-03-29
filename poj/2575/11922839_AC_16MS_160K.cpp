#include<cstdio>
#include<cstring>
int a[3010],n;
bool f[3010];
int abs(int x){
	return (x>0?x:-x);
}
bool yes(){
	for (int i=1;i<n;i++) if (!f[i]) return 0;
	return 1;
}
int main(){
	while (scanf("%d",&n)!=EOF){
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		for (int i=1;i<n;i++) f[abs(a[i]-a[i+1])]=1;
		if (yes()) printf("Jolly\n");else printf("Not jolly\n");
	}
}