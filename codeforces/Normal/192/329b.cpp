#include <cstdio>
struct rec{int x,y,step;};
rec b[1001000];
char s[1010][1010];
bool v[1010][1010]={0},flag;
int n,m,x,y,p,q,ans,st,d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",s[i]);
	flag=0;
	for (int i=0;i<n;i++) if (!flag)
		for (int j=0;j<m;j++) if (s[i][j]=='E'){
			flag=1;
			x=i;
			y=j;
			break;
		}
	p=q=1;
	st=1000000000;
	b[1].x=x;
	b[1].y=y;
	b[1].step=0;
	v[x][y]=1;
	ans=0;
	while (b[p].step<st){
		for (int i=0;i<4;i++){
			x=b[p].x+d[i][0];
			y=b[p].y+d[i][1];
			if (0<=x && x<n && 0<=y && y<m && s[x][y]!='T' && !v[x][y]){
				q++;
				b[q].x=x;
				b[q].y=y;
				v[x][y]=1;
				b[q].step=b[p].step+1;
				if (s[x][y]=='S') st=b[q].step;else ans=ans+s[x][y]-48;
			}
		}
		p++;
	}
	printf("%d\n",ans);
}