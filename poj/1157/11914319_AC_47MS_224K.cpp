#include<cstdio>
#include<cstring>
int a[101][101],f[101][101],n,m,ans;
int max(int a,int b){
	return (a>b?a:b);
}
int main(){
	scanf("%d%d",&n,&m);
	memset(f,128,sizeof(f));
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	f[0][0]=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=m+i-n;j++)
			for (int k=i-1;k<=j-1;k++)
				f[i][j]=max(f[i][j],f[i-1][k]+a[i][j]);
	ans=-2147483647;
	for (int i=n;i<=m;i++) ans=(ans>f[n][i]?ans:f[n][i]);
	printf("%d\n",ans);
}