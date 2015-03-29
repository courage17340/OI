/*
ID: courage2
PROG: numtri
LANG: C++
*/
#include <cstdio>
int n,a[1010][1010] = {{0}},f[1010][1010] = {{0}};
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= i;j++) scanf("%d",&a[i][j]);
	for (int i = n;i >= 1;i--)
		for (int j = 1;j <= i;j++) f[i][j] = a[i][j] + max(f[i + 1][j],f[i + 1][j + 1]);
	printf("%d\n",f[1][1]);
}
