/*
ID: courage2
PROG: castle
LANG: C++
*/
#include <cstdio>
int a[51][51],f[2510],b[2510] = {0},m,n,x,y,p,q,c,ans;
int father(int x){
	if (f[x] == x) return x;
	f[x] = father(f[x]);
	return f[x];
}
inline int no(int i,int j){
	return (i - 1) * m + j;
}
int main(){
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) scanf("%d",&a[i][j]);
	for (int i = 1;i <= n * m;i++) f[i] = i;
	for (int i = 1;i < n;i++)
		for (int j = 1; j <= m;j++) if (a[i][j] < 8){
			x = no(i,j);
			y = no(i + 1,j);
			if (father(x) != father(y)) f[f[x]] = f[y];
		}
	for (int i = 1;i <= n;i++)
		for (int j = 2;j <= m;j++) if (!(a[i][j] & 1)){
			x = no(i,j);
			y = no(i,j - 1);
			if (father(x) != father(y)) f[f[x]] = f[y];
		}
	for (int i = 1;i <= n * m;i++) b[father(i)]++;
	ans = p = q = 0;
	for (int j = 1;j <= m;j++)
		for (int i = n;i >= 1;i--){
			x = no(i,j);
			if (i > 1){
				y = no(i - 1,j);
				if (f[x] != f[y] && ans < b[f[x]] + b[f[y]]){
					p = i;
					q = j;
					c = 'N';
					ans = b[f[x]] + b[f[y]];
				}
			}
			if (j < m){
				y = no(i,j + 1);
				if (f[x] != f[y] && ans < b[f[x]] + b[f[y]]){
					p = i;
					q = j;
					c = 'E';
					ans = b[f[x]] + b[f[y]];
				}
			}
		}
	x = y = 0;
	for (int i = 1;i <= n * m;i++) if (b[i]) x++;
	for (int i = 1;i <= n * m;i++) if (y < b[i]) y = b[i];
	printf("%d\n%d\n%d\n%d %d %c\n",x,y,ans,p,q,c);
}
