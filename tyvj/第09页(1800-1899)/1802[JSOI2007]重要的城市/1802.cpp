#include <cstdio>
#include <cstring>
int a[210][210],ans[210],f[210][210] = {{0}},n,m,x,y,z;
bool v[210] = {0};
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	memset(a,1,sizeof a);
	scanf("%d%d",&n,&m);
	while (m--){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y] = min(a[x][y],z);
		a[y][x] = a[x][y];
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++) if (i != j){
				if (a[i][j] == a[i][k] + a[k][j]) f[i][j] = -1;
				if (a[i][j] > a[i][k] + a[k][j]){
					a[i][j] = a[i][k] + a[k][j];
					f[i][j] = k;
				}
			}
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) if (i != j) v[f[i][j]] = 1;
	m = 0;
	for (int i = 1;i <= n;i++) if (v[i]) ans[++m] = i;
	if (!m) puts("No important cities.");
	else{
		for (int i = 1;i < m;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[m]);
	}
}
