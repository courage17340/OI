#include <cstdio>
#include <algorithm>
#include <cstring>
int a[110],b[110],n,m,p;
typedef long long ll;
ll f[100][100][100];
ll min(ll a,ll b){
	return a < b ? a : b;
}
int main(){
	scanf("%d%d%d",&p,&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	for (int i = 1;i <= m;i++) scanf("%d",b + i);
	std::sort(a + 1,a + n + 1);
	std::sort(b + 1,b + m + 1);
	memset(f,1,sizeof f);
	for (int i = 0;i <= n;i++)
		for (int j = 0;j <= m;j++) f[0][i][j] = 0;
	for (int i = 1;i <= p;i++)
		for (int j = i;j <= n;j++)
			for (int k = i;k <= m;k++){
				f[i][j][k] = min(f[i][j][k - 1],f[i][j - 1][k]);
				f[i][j][k] = min(f[i][j][k],f[i - 1][j - 1][k - 1] + (a[j] - b[k]) * (a[j] - b[k]));
			}
	printf("%lld\n",f[p][n][m]);
}
