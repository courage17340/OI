#include <cstdio>
bool f[110][110] = {{0}};
char s[2][10] = {"Malvika","Akshat"};
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) f[i][1] = 1;
	for (int i = 1;i <= m;i++) f[1][i] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 2;j <= m;j++) f[i][j] = !f[i - 1][j - 1];
	puts(s[f[n][m]]);
}
