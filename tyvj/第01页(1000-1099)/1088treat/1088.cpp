#include <cstdio>
typedef long long ll;
ll f[2010][2010] = {{0}};
int a[2010],n;
ll max(ll a,ll b){return a > b ? a : b;}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	for (int i = 1;i <= n;i++) f[i][i] = n * a[i];
	for (int t = 1;t < n;t++)
		for (int i = 1;i + t <= n;i++){
			int j = i + t;
			f[i][j] = max(f[i][j - 1] + (n - t) * a[j],f[i + 1][j] + (n - t) * a[i]);
		}
	printf("%lld\n",f[1][n]);
}
