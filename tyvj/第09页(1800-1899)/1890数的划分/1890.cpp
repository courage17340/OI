#include<cstdio>
int f[210][7]={0},n,k;
int main(){
	scanf("%d%d",&n,&k);
	f[1][1]=1;
	for (int i=2;i<=n;i++)
		for (int j=1;j<=i && j<=k;j++)
			f[i][j]=f[i-1][j-1]+f[i-j][j];
	printf("%d\n",f[n][k]);
}
