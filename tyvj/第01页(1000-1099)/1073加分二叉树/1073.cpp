#include <cstdio>
typedef long long ll;
int a[41],b[41],p[40][40],n,m;
ll f[40][40] = {{0}},x;
void out(int l,int r){
	if (l > r) return;
	b[++m] = p[l][r];
	out(l,p[l][r] - 1);
	out(p[l][r] + 1,r);
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	for (int i = 0;i <= n + 1;i++) for (int j = 0;j <= n + 1;j++) f[i][j] = 1;
	for (int i = 1;i <= n;i++){
		f[i][i] = a[i];
		p[i][i] = i;
	}
	for (int t = 1;t < n;t++)
		for (int i = 1;i + t <= n;i++){
			int j = i + t;
			f[i][j] = -1;
			for (int k = i;k <= j;k++){
				x = f[i][k - 1] * f[k + 1][j] + a[k];
				if (x > f[i][j]){
					f[i][j] = x;
					p[i][j] = k;
				}
			}
		}
	printf("%lld\n",f[1][n]);
	m = 0;
	out(1,n);
	for (int i = 1;i < m;i++) printf("%d ",b[i]);
	printf("%d\n",b[m]);
}
