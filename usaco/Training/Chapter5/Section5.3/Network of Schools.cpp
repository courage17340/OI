/*
USER: courage2
LANG: C++
TASK: schlnet
*/
#include <cstdio>
int n,x,y,f[110];
bool a[110][110] = {{0}},u[110] = {0},v[110] = {0};
int father(int x){
	return f[x] == x ? x : f[x] = father(f[x]);
}
bool single(){
	for (int i = 2;i <= n;i++) if (father(i) != father(1)) return 0;
	return 1;
}
int main(){
	freopen("schlnet.in","r",stdin);
	freopen("schlnet.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		a[i][i] = 1;
		f[i] = i;
		while (1){
			scanf("%d",&x);
			if (!x) break;
			a[i][x] = 1;
		}
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++) if (i != j) a[i][j] |= (a[i][k] && a[k][j]);
	for (int i = 1;i < n;i++)
		for (int j = i + 1;j <= n;j++) if (a[i][j] && a[j][i] && father(i) != father(j)) f[f[i]] = f[j];
	if (single()) printf("1\n0\n");else{
		for (int i = 1;i <= n;i++) if (father(i) == i)
			for (int j = 1;j <= n;j++) if (i != j && father(j) == j && a[i][j]){
				u[i] = v[j] = 1;
			}
		x = y = 0;
		for (int i = 1;i <= n;i++) if (father(i) == i && !v[i]) x++;
		for (int i = 1;i <= n;i++) if (father(i) == i && !u[i]) y++;
		printf("%d\n%d\n",x,x > y ? x : y);
	}
}
