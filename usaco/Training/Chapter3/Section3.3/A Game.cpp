/*
USER: courage2
LANG: C++
TASK: game1
*/
#include <cstdio>
#include <cstring>
int a[110],n,x,y,s[110] = {0},k,f[110][110];
int min(int a,int b){
	return a < b ? a : b;
}
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	for (int i = 1;i <= n;i++) f[i][i] = a[i];
	for (int k = 1;k < n;k++)
		for (int i = 1;i + k <= n;i++){
			int j = i + k;
			f[i][j] = max(s[j] - s[i] - f[i + 1][j] + a[i],s[j - 1] - s[i - 1] - f[i][j - 1] + a[j]);
		}
	printf("%d %d\n",f[1][n],s[n] - f[1][n]);
}
