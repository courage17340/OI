#include<cstdio>
int n,m,x,y,p,q,i,j,d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct rec{int x,y,sta,step;};
rec b[500010];
char a[510][510];
bool v[510][510]={{0}};
int main(){
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++) scanf("%s",a[i]);
	scanf("%d%d%d%d",&x,&y,&p,&q);
	i=j=1;
	x--;
	y--;
	p--;
	q--;
	b[1].x=x;
	b[1].y=y;
	v[x][y]=1;
	b[1].sta=0;
	b[1].step=0;
	while (i<j+1){
		if (b[i].sta){
			j++;
			b[j].x=b[i].x;
			b[j].y=b[i].y;
			b[j].step=b[i].step+1;
			b[j].sta=0;
			i++;
			continue;
		}
		if (b[i].x==p && b[i].y==q){
			printf("%d",b[i].step);
			return 0;
		}
		for (int k=0;k<4;k++){
			x=b[i].x+d[k][0];
			y=b[i].y+d[k][1];
			if (0<=x && x<n && 0<=y && y<m && !v[x][y]){
				v[x][y]=1;
				j++;
				b[j].x=x;
				b[j].y=y;
				b[j].step=b[i].step+1;
				b[j].sta=(a[b[i].x][b[i].y]==a[x][y]?0:1);
			}
		}
		i++;
	}
}
