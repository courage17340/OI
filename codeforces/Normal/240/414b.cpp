#include <cstdio>
const int md = 1000000007;
int n,k,f[2010][2010] = {0},ans;
int main(){
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++) f[1][i] = 1;
	for (int i = 1;i < k;i++)
		for (int j = 1;j <= n;j++)
			for (int k = j;k <= n;k += j) f[i + 1][k] = (f[i + 1][k] + f[i][j]) % md;
	ans = 0;
	for (int i = 1;i <= n;i++) ans = (ans + f[k][i]) % md;
	printf("%d\n",ans);
}
