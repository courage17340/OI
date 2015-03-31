#include<cstdio>
char s[20];
int a[11],n,m,x,y,p,ans[1010];
bool f[1010][11][11]={{{0}}},flag;
int main(){
	scanf("%s",s);
	scanf("%d",&m);
	p=0;
	for (int i=0;i<10;i++) if (s[i]=='1'){
		p++;
		a[p]=i+1;
	}
	for (int i=1;i<=p;i++) f[1][a[i]][a[i]]=1;
	for (int i=2;i<=m;i++)
		for (int j=1;j<=p;j++){
			x=a[j];
			for (int k=1;k<x;k++)  for (int r=1;r<=p;r++) if (x!=a[r]) f[i][x][k]|=f[i-1][a[r]][x-k];
		}
	flag=0;
	for (int j=1;j<=p;j++) if (!flag) for (int k=1;k<=10;k++) if (f[m][a[j]][k]){
		ans[m]=a[j];
		y=k;
		flag=1;
		break;
	}
	if (!flag) printf("NO");else{
		printf("YES\n");
		for (int i=m-1;i>=1;i--)
			for (int j=1;j<=p;j++) if (a[j]!=ans[i+1] && f[i][a[j]][ans[i+1]-y]){
				y=ans[i+1]-y;
				ans[i]=a[j];
				break;
			}
		for (int i=1;i<m;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[m]);
	}
}
