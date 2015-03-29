#include <cstdio>
#include <cstring>
int n,a[110],f[110][110] = {{0}};
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n + 1;i++) scanf("%d",&a[i]);
	for (int l = 1;l < n;l++)
		for (int i = 1;i + l <= n;i++){
			int j = i + l;
			f[i][j] = 1e9;
			for (int k = i;k < j;k++) f[i][j] = min(f[i][j],f[i][k] + f[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
		}
	printf("%d",f[1][n]);
}
