#include <cstdio>
#include <cstring>
int n,ans,a[21][21],f[41][21][21][21] = {{{{0}}}};
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) scanf("%d",&a[i][j]);
	ans = a[1][1] + a[n][n];
	a[1][1] = a[n][n] = 0;
	for (int i = 1;i <= n * 2 - 2;i++)
		for (int j = max(1,i + 2 - n);j <= i + 1 && j <= n;j++)
			for (int k = j;k <= i + 1 && k <= n;k++)
				for (int p = k;p <= i + 1 && p <= n;p++){
				f[i][j][k][p] = f[i - 1][j][k][p];
				f[i][j][k][p] = max(f[i][j][k][p],f[i - 1][j - 1][k][p]);
				f[i][j][k][p] = max(f[i][j][k][p],f[i - 1][j][k - 1][p]);
				f[i][j][k][p] = max(f[i][j][k][p],f[i - 1][j][k][p - 1]);
				f[i][j][k][p] = max(f[i][j][k][p],f[i - 1][j - 1][k - 1][p]);
				f[i][j][k][p] = max(f[i][j][k][p],f[i - 1][j - 1][k][p - 1]);
				f[i][j][k][p] = max(f[i][j][k][p],f[i - 1][j][k - 1][p - 1]);
				f[i][j][k][p] = max(f[i][j][k][p],f[i - 1][j - 1][k - 1][p - 1]);
				f[i][j][k][p] += a[i + 2 - j][j] + a[i + 2 - k][k] + a[i + 2 - p][p];
				if (j == k) f[i][j][k][p] -= a[i + 2 - j][j];
				if (k == p) f[i][j][k][p] -= a[i + 2 - k][k];
			}
	ans += f[n * 2 - 2][n][n][n];
	printf("%d",ans);
}
