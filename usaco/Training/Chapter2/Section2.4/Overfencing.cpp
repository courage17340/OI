/*
ID: courage2
TASK: maze1
LANG: C++
*/
#include <cstdio>
#include <cstring>
int a[210][80],f[210][80],g[210][80],n,ans,m,x,y,p,q,d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},X[2],Y[2];
struct rec{int x,y;};
rec b[20010];
bool v[210][80];
char s[100];
int min(int a,int b){
	if (!a) return b;
	if (!b) return a;
	return a < b ? a : b;
}
int max(int a,int b){return a > b ? a : b;}
int main(){
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	scanf("%d%d",&m,&n);
	gets(s);
	n = n * 2 + 1;
	m = m * 2 + 1;
	for (int i = 1;i <= n;i++){
		gets(s);
		for (int j = 1;j <= m;j++) a[i][j] = s[j - 1];
	}
	p = -1;
	for (int i = 1;i <= m;i++) if (a[1][i] == ' '){
		p++;
		X[p] = 1;
		Y[p] = i;
	}
	for (int i = 1;i <= m;i++) if (a[n][i] == ' '){
		p++;
		X[p] = n;
		Y[p] = i;
	}
	for (int i = 2;i < n;i++) if (a[i][1] == ' '){
		p++;
		X[p] = i;
		Y[p] = 1;
	}
	for (int i = 2;i < n;i++) if (a[i][m] == ' '){
		p++;
		X[p] = i;
		Y[p] = m;
	}
	memset(v,0,sizeof v);
	f[X[0]][Y[0]] = 1;
	v[X[0]][Y[0]] = 1;
	p = q = 1;
	b[p].x = X[0];
	b[p].y = Y[0];
	while (p <= q){
		for (int k = 0;k < 4;k++){
			x = b[p].x + d[k][0];
			y = b[p].y + d[k][1];
			if (x < 1 || x > n || y < 1 || y > m || v[x][y] || a[x][y] != ' ') continue;
			v[x][y] = 1;
			f[x][y] = f[b[p].x][b[p].y] + 1;
			q++;
			b[q].x = x;
			b[q].y = y;
		}
		p++;
	}
	memset(v,0,sizeof v);
	g[X[1]][Y[1]] = 1;
	v[X[1]][Y[1]] = 1;
	p = q = 1;
	b[p].x = X[1];
	b[p].y = Y[1];
	while (p <= q){
		for (int k = 0;k < 4;k++){
			x = b[p].x + d[k][0];
			y = b[p].y + d[k][1];
			if (x < 1 || x > n || y < 1 || y > m || v[x][y] || a[x][y] != ' ') continue;
			v[x][y] = 1;
			g[x][y] = g[b[p].x][b[p].y] + 1;
			q++;
			b[q].x = x;
			b[q].y = y;
		}
		p++;
	}
	ans = 0;
	for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++){
		f[i][j] = min(f[i][j],g[i][j]);
		ans = max(ans,f[i][j]);
	}
	printf("%d\n",ans >> 1);
}
