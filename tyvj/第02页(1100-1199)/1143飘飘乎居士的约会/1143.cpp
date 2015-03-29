#include <cstdio>
char s[1010][1010];
int n,m,p,q,x,y,f[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct rec{int x,y,c;bool f;};
rec b[2000010];
bool v[1010][1010][2] = {{{0}}};
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%s",s[i]);
	p = q = 1;
	b[1].x = 1;
	b[1].y = 1;
	b[1].c = 0;
	b[1].f = 1;
	v[1][1][0] = v[1][1][1] = 1;
	while (p <= q){
		if (b[p].x == n && b[p].y == m){
			printf("%d",b[p].c);
			return 0;
		}
		for (int k = 0;k < 4;k++){
			x = b[p].x + f[k][0];
			y = b[p].y + f[k][1];
			if (x < 1 || x > n || y < 1 || y > m) continue;
			if (s[x][y - 1] == '.' && !v[x][y][b[p].f]){
				v[x][y][b[p].f] = 1;
				q++;
				b[q].x = x;
				b[q].y = y;
				b[q].c = b[p].c + 1;
				b[q].f = b[p].f;
			}
			if (s[x][y - 1] == '*' && b[p].f && !v[x][y][0]){
				q++;
				b[q].x = x;
				b[q].y = y;
				b[q].c = b[p].c + 1;
				b[q].f = 0;
			}
		}
		p++;
	}
	printf("no");
}
