#include<cstdio>
#include<cstring>
int a[101][101],n,m,k,x,y,ans,p;
int main(){
	while (scanf("%d",&n)){
		if (n==0) break;
		memset(a,255,sizeof(a));
		for (int i=1;i<=n;i++){
			scanf("%d",&k);
			for (int j=1;j<=k;j++){
				scanf("%d%d",&x,&y);
				a[i][x]=y;
			}
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) if (i!=j)
				for (int q=1;q<=n;q++) if (q!=i && q!=j)
					if ((a[i][j]==-1 || a[i][j]>a[i][q]+a[q][j]) && a[i][q]>=0 && a[q][j]>=0)
						a[i][j]=a[i][q]+a[q][j];
		ans=-1;
		for (int i=1;i<=n;i++){
			p=-1;
			for (int j=1;j<=n;j++) if (i!=j){
				if (p<a[i][j]) p=a[i][j];
				if (a[i][j]==-1){
					p=-1;
					break;
				}
			}
			if (ans==-1 || ans>p && p>=0){
				ans=p;
				k=i;
			}
		}
		if (ans>=0) printf("%d %d\n",k,ans);else printf("disjoint\n");
	}
}