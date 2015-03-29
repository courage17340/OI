#include <cstdio>
int n,m,l,r,p,q,x,y,S,x0,y0,x1,y1,ans,f[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char s[1010][1010];
struct rec{int x,y;};
rec b[1000010];
int min(int a,int b){return a < b ? a : b;}
int max(int a,int b){return a > b ? a : b;}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%s",s[i]);
	ans = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < m;j++) if (s[i][j] == '#'){
			s[i][j] = '.';
			p = q = 1;
			b[p].x = i;
			b[p].y = j;
			S = 1;
			x0 = x1 = i;
			y0 = y1 = j;
			while (p <= q){
				for (int k = 0;k < 4;k++){
					x = b[p].x + f[k][0];
					y = b[p].y + f[k][1];
					if (x < 1 || x > n || y < 0 || y >= m || s[x][y] != '#') continue;
					q++;
					b[q].x = x;
					b[q].y = y;
					s[x][y] = '.';
					S++;
					x0 = min(x0,x);
					x1 = max(x1,x);
					y0 = min(y0,y);
					y1 = max(y1,y);
				}
				p++;
			}
			if (S != (x1 - x0 + 1) * (y1 - y0 + 1)){
				printf("Bad placement.");
				return 0;
			}else ans++;
		}
	printf("There are %d ships.",ans);
}
