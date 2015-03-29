#include<cstdio>
int f[11][11]={0},n,m,t;
int main(){
	for (int i=0;i<11;i++) f[0][i]=1;
	for (int i=0;i<11;i++) f[i][1]=1;
	for (int i=1;i<11;i++)
		for (int j=1;j<11;j++){
			f[i][j]=f[i][j-1];
			if (i>=j) f[i][j]+=f[i-j][j];
		}
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		scanf("%d%d",&m,&n);
		printf("%d\n",f[m][n]);
	}
}