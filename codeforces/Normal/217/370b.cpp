#include <cstdio>
int n,x,a[110][110],m[110];
bool f[110][110]={{0}},g[110],ans[110],y;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) ans[i] = 1;
	for (int i = 1;i <= n;i++){
		scanf("%d",&m[i]);
		for (int j = 1;j <= m[i];j++){
			scanf("%d",&a[i][j]);
			f[i][a[i][j]] = 1;
		}
	}
	for (int i = 1;i <= n;i++){
		y = 1;
		for (int j = 1;j <= n;j++) g[j] = 1;
		for (int j = 1;j <= m[i];j++)
			for (int k = 1;k <= n;k++) if (!f[k][a[i][j]]) g[k] = 0;
		for (int j = 1;j <= n;j++) if (i != j && g[j]) ans[j] = 0;
	}
	for (int i = 1;i <= n;i++) if (ans[i]) printf("YES\n");else printf("NO\n");
}
