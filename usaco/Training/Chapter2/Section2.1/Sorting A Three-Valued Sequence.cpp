/*
ID: courage2
PROG: sort3
LANG: C++
*/
#include <cstdio>
#include <algorithm>
int n,a[1010],b[4][4] = {{0}},f[4] = {0},ans,x;
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	for (int i = 1;i <= n;i++) f[a[i]]++;
	for (int i = 1;i <= f[1];i++) if (a[i] > 1) b[1][a[i]]++;
	for (int i = f[1] + 1;i <= f[1] + f[2];i++) if (a[i] != 2) b[2][a[i]]++;
	for (int i = f[1] + f[2] + 1;i <= n;i++) if (a[i] != 3) b[3][a[i]]++;
	ans = 0;
	for (int i = 1;i <= 2;i++) for (int j = i + 1;j <= 3;j++){
		x = min(b[i][j],b[j][i]);
		ans += x;
		b[i][j] -= x;
		b[j][i] -= x;
	}
	x = 0;
	for (int i = 1;i <= 3;i++) for (int j = 1;j <= 3;j++) x += b[i][j];
	ans += x / 3 * 2;
	printf("%d\n",ans);
}
