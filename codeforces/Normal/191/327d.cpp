#include<cstdio>
#include<cstring>
int n,m,a[510][510]={{0}},p,q,k=0,f[4][2]={{1,0},{-1,0},{0,1},{0,-1}},ans[750010][3],x,y;
char s[510];
struct rec{int x,y;};
rec b[250010];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		for (int j=1;j<=m;j++) a[i][j]=(s[j-1]=='.'?1:0);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]){
				p=q=1;
				a[i][j]=0;
				b[1].x=i;
				b[1].y=j;
				while (p<q+1){
					for (int r=0;r<4;r++){
						x=b[p].x+f[r][0];
						y=b[p].y+f[r][1];
						if (0<x&&x<=n&&0<y&&y<=m&&a[x][y]){
							q++;
							b[q].x=x;
							b[q].y=y;
							a[x][y]=0;
						}
					}
					p++;
				}
				for (int i=k+1;i<=k+q;i++){
					ans[i][0]=b[i-k].x;
					ans[i][1]=b[i-k].y;
					ans[i][2]=1;
				}
				k+=q;
				for (int i=1;i<=q-1;i++){
					k++;
					x=b[q-i+1].x;
					y=b[q-i+1].y;
					ans[k][0]=x;
					ans[k][1]=y;
					ans[k][2]=3;
					k++;
					ans[k][0]=x;
					ans[k][1]=y;
					ans[k][2]=2;
				}
			}
	printf("%d\n",k);
	for (int i=1;i<=k;i++){
		if (ans[i][2]==3) printf("D");else if (ans[i][2]==2) printf("R");else printf("B");
		printf(" %d %d\n",ans[i][0],ans[i][1]);
	}
}
