#include <cstdio>
#include <cstring>
const int oo = 1 << 30;
typedef long long ll;
int n,m,a[310],w[310][310],f[310][310]={{0}},d[310][310]={{0}},mid;
ll s[310]={0},x;
inline int abs(int x){
	return x > 0 ? x : -x;
}
inline int dis(int a,int b){
	return abs(a - b);
}
inline int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++){
			mid = (i + j) >> 1;
			w[i][j] = s[j] - s[mid] - (ll)(j - mid) * a[mid] + (ll)(mid - i) * a[mid] - s[mid - 1] + s[i - 1];
		}
	for (int i = 1;i <= n;i++) f[1][i] = w[1][i];
	for (int i = 2;i <= m;i++){
		d[i][n + 1] = n - 1;
		for (int j = n;j > i;j--){
			f[i][j] = oo;
			for (int k = d[i - 1][j];k <= d[i][j + 1];k++){
				int t = f[i - 1][k] + w[k + 1][j];
				if (t < f[i][j]){
					f[i][j] = t;
					d[i][j] = k;
				}
			}
		}
	}
	printf("%d\n",f[m][n]);
}