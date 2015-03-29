#include <cstdio>
int max(int a,int b){
	return a > b ? a : b;
}
int k,m,n,v[210],c[210],f[21][1010];
int main(){
	scanf("%d%d%d",&k,&m,&n);
	for (int i = 1;i <= n;i++) scanf("%d%d",&v[i],&c[i]);
	for (int i = 0;i <= k;i++) for (int j = 0;j <= m;j++) f[i][j] = -1e9;
	f[0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = k;j >= 1;j--)
			for (int p = m;p >= v[i];p--)
				f[j][p] = max(f[j][p],f[j - 1][p - v[i]] + c[i]);
	if (f[k][m] < 0) printf("impossible\n");else printf("%d\n",f[k][m]);
}
