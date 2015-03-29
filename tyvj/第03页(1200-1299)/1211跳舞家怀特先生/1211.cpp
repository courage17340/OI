#include <cstdio>
int n,a[10010],f[10010][5],b[5][5],ans;
int min(int a,int b){
	return a < b ? a : b;
}
bool yes(int a,int b,int c,int d){
	if (a && b && a == b) return 0;
	if (c && d && c == d) return 0;
	return (a == d || b == d);
}
int g(int a,int b){
	if (a == b) return 1;
	if (a * b == 0) return 2;
	if (a - b == 2 || b - a == 2) return 4;
	return 3;
}
int cost(int A,int B,int C,int D){
	if (A == C) return b[B][D];
	if (A == D) return b[B][C];
	if (B == C) return b[A][D];
	return b[A][C];
}
int main(){
	for (int i = 0;i < 5;i++) for (int j = 0;j < 5;j++) b[i][j] = g(i,j);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	a[0] = 0;
	f[0][0] = 0;
	f[0][1] = f[0][2] = f[0][3] = f[0][4] = 1e8;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= 4;j++){
			f[i][j] = 1e8;
			for (int k = 0;k <= 4;k++) if (yes(a[i - 1],k,a[i],j)) f[i][j] = min(f[i][j],f[i - 1][k] + cost(a[i - 1],k,a[i],j));
		}
	ans = f[n][0];
	for (int i = 1;i <= 4;i++) if (a[n] != i) ans = min(ans,f[n][i]);
	printf("%d",ans);
}
