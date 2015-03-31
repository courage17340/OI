#include <cstdio>
int a[41][41],b[41][41] = {{0}},f[41][41][41][41]={{{{0}}}},g[41][41][41][41],n,m,q,x,y,x1,y1;
char s[50];
bool r[41][41][41][41] ={{{{0}}}},v[41][41][41][41] = {{{{0}}}};
int sum(int i,int j,int k,int l){
	return b[k][l] - b[i - 1][l] - b[k][j - 1] + b[i - 1][j - 1];
}
int work(int i,int j,int k,int l){
	if (i > k || j > l) return 0;
	if (i ==k && j == l) return r[i][j][k][l];
	if (v[i][j][k][l]) return f[i][j][k][l];
	f[i][j][k][l] = work(i,j,k,l - 1) + work(i,j,k - 1,l) - work(i,j,k - 1,l - 1) + g[i][j][k][l];
	v[i][j][k][l] = 1;
	return f[i][j][k][l];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1;i <= n;i++){
		scanf("%s",s);
		for (int j = 1;j <= m;j++) a[i][j] = s[j - 1] - '0';
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
	for (int i = 1;i <= n;i++) 
		for (int j = 1;j <= m;j++)
			for (int k = i;k <= n;k++)
				for (int l = j;l <= m;l++) r[i][j][k][l] = (sum(i,j,k,l) == 0);
	for (int i = n;i >= 1;i--)
		for (int j = m;j >= 1;j--)
			for (int k = i;k >= 1;k--)
				for (int l = j;l >= 1;l--){
					g[k][l][i][j] = g[k + 1][l][i][j] + g[k][l + 1][i][j] - g[k + 1][l + 1][i][j] + r[k][l][i][j];
//					printf("%d\n",g[k][l][i][j]);
				}
//	while (scanf("%d%d%d%d",&x,&y,&x1,&y1)!=EOF) printf("%d\n",g[x][y][x1][y1]);
/*	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			for (int k = i;k <= n;k++)
				for (int l = j;l <= m;l++)
					f[i][j][k][l] = f[i][j][k][l - 1] + f[i][j][k - 1][l] - f[i][j][k - 1][j - 1] + (a[k][l] == 0) + r[i][j][k][l];*/
	while (q--){
		scanf("%d%d%d%d",&x,&y,&x1,&y1);
		printf("%d\n",work(x,y,x1,y1));
	}
}
