#include<cstdio>
#include<algorithm>
int a[60]={0},ans,n,m,p;
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	ans=a[n]-a[n-m+1];
	for (int i=n-1;i>=m;i--) if (ans>a[i]-a[i-m+1]) ans=a[i]-a[i-m+1];
	printf("%d",ans);
}
