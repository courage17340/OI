/*
USER: courage2
LANG: C++
TASK: bigbrn
*/
#include <cstdio>
int a[1010][1010] = {{0}},f[1010][1010] = {{0}},n,m,x,y,ans = 0;
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	freopen("bigbrn.in","r",stdin);
	freopen("bigbrn.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) f[i][j] = 1;
	for (int i = 1;i <= m;i++){
		scanf("%d%d",&x,&y);
		a[x][y] = 1;
		f[x][y] = 0;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++){
			if (!a[i][j]) f[i][j] = min(f[i - 1][j - 1],min(f[i - 1][j],f[i][j - 1])) + 1;
			if (ans < f[i][j]) ans = f[i][j];
		}
	printf("%d\n",ans);
}
