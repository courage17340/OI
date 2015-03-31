#include<cstdio>
int a[110]={0},x,ans,n,m;
inline int max(int a,int b){
	return (a>b?a:b);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=a[i-1]+x;
	}
	ans=-n;
	for (int i=1;i<=n;i++) for (int j=i;j<=n;j++) ans=max(ans,a[n]-(a[j]-a[i-1])+(j-i+1-a[j]+a[i-1]));
	printf("%d",ans);
}
