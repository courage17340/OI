#include<cstdio>
const int mm=1000000;
int a[101][101],n,m,k,x,y,ans,p;
int main(){
	while (scanf("%d",&n)){
		if (n==0) break;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (i==j) a[i][j]=0;else a[i][j]=mm;
		for (int i=1;i<=n;i++){
			scanf("%d",&k);
			for (int j=1;j<=k;j++){
				scanf("%d%d",&x,&y);
				a[i][x]=y;
			}
		}
		for (p=1;p<=n;p++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++) if (i!=j)
					if (a[i][j]>a[i][p]+a[p][j]) a[i][j]=a[i][p]+a[p][j];
		ans=mm;
		for (int i=1;i<=n;i++){
			p=0;
			for (int j=1;j<=n;j++) if (i!=j){
				if (p<a[i][j]) p=a[i][j];
				if (a[i][j]==mm){
					p=mm;
					break;
				}
			}
			if (ans>p){
				ans=p;
				k=i;
			}
		}
		if (ans<mm) printf("%d %d\n",k,ans);else printf("disjoint\n");
	}
}