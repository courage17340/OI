#include <cstdio>
int n,m,a[50010][6];
long long f[50010] = {0};
int main(){
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= m;i++) for (int j = 1;j <= n;j++) scanf("%d",&a[i][j]);
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++) f[j] = (f[j - 1] > f[j] ? f[j - 1] : f[j]) + a[j][i];
	}
	for (int i = 1;i < m;i++) printf("%I64d ",f[i]);
	printf("%I64d\n",f[m]);
}
