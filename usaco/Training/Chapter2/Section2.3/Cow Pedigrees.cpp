/*
ID: courage2
TASK: nocows
LANG: C++
*/
#include <cstdio>
#include <cmath>
const int md = 9901;
int f[210][110] = {{0}},n,k,ans;
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= k;i++) f[1][i] = 1;
	for (int i = 3;i <= n;i += 2)
		for (int j = 2;j <= k;j++)
			for (int r = 1;r < i;r += 2)
				f[i][j] = (f[i][j] + f[r][j - 1] * f[i - r - 1][j - 1]) % md;
	ans = (f[n][k] - f[n][k - 1]) % md;
	if (ans < 0) ans += md;
	printf("%d\n",ans);
}
