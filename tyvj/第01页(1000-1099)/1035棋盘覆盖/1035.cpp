#include<cstdio>
#include<cstring>
int n,m,k,x,y,r=0,ans=0,link[10010],d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool v[10010],f[101][101]={{0}};
struct node{int x;node *next;};
node *a[10010],*p,*q;
bool find(int x){
	node *p=a[x];
	while (p->next!=0){
		p=p->next;
		if (!v[p->x]){
			v[p->x]=1;
			if (link[p->x]==-1 || find(link[p->x])){
				link[p->x]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	memset(link,-1,sizeof(link));
	scanf("%d%d",&n,&k);
	while (k--){
		scanf("%d%d",&x,&y);
		f[x][y]=1;
	}
	for (int i=1;i<=n*n;i++){
		a[i]=new node;
		a[i]->next=0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (!f[i][j] && (i+j)&1){
			p=a[(i-1)*n+j];
			for (int k=0;k<4;k++){
				x=i+d[k][0];
				y=j+d[k][1];
				if (0<x && x<=n && 0<y && y<=n && !f[x][y]){
					q=new node;
					q->next=0;
					q->x=(x-1)*n+y;
					p->next=q;
					p=q;
				}
			}
		}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (!f[i][j] && (i+j)&1){
		memset(v,0,sizeof(v));
		if (find((i-1)*n+j)) ans++;
	}
	printf("%d",ans);
}
