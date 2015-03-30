#include <cstdio>
#include <cstring>
struct rec{int x,y;};
rec b[40010];
int a[210][210],f[210][210],n,m,x,y,p,q,d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool v[210][210] = {{0}};
char s[210];
int main(){
	memset(f,1,sizeof f);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%s",s);
		for (int j = 0;j < m;j++) a[i][j + 1] = s[j];
	}
	p = 1;
	q = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) if (a[i][j] == '1'){
			v[i][j] = 1;
			f[i][j] = 0;
			q++;
			b[q].x = i;
			b[q].y = j;
		}
	while (p <= q){
		for (int k = 0;k < 4;k++){
			x = b[p].x + d[k][0];
			y = b[p].y + d[k][1];
			if (0 < x && x <= n && 0 < y && y <= m && !v[x][y]){
				q++;
				b[q].x = x;
				b[q].y = y;
				f[x][y] = f[b[p].x][b[p].y] + 1;
				v[x][y] = 1;
			}
		}
		p++;
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j < m;j++) printf("%d ",f[i][j]);
		printf("%d\n",f[i][m]);
	}
}
