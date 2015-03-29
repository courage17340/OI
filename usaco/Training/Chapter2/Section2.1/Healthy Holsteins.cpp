/*
ID: courage2
PROG: holstein
LANG: C++
*/
#include <cstdio>
int n,ans,m,a[30],b[30] = {0},c[30],d[30],f[30][30] = {{0}};
void search(int k,int x){
	if (k >= ans) return;
	c[k] = x;
	for (int i = 1;i <= n;i++) b[i] += f[x][i];
	bool g = 1;
	for (int i = 1;i <= n;i++) if (b[i] < a[i]) g = 0;
	if (g){
		ans = k;
		for (int i = 1;i <= k;i++) d[i] = c[i];
		for (int i = 1;i <= n;i++) b[i] -= f[x][i];
		return;
	}
	if (k == m){
		for (int i = 1;i <= n;i++) b[i] -= f[x][i];
		return;
	}
	for (int i = x + 1;i <= m;i++) search(k + 1,i);
	for (int i = 1;i <= n;i++) b[i] -= f[x][i];
}
int main(){
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i = 1;i <= m;i++) for (int j = 1;j <= n;j++) scanf("%d",&f[i][j]);
	ans = n + 1;
	search(0,0);
	printf("%d",ans);
	for (int i = 1;i <= ans;i++) printf(" %d",d[i]);
	printf("\n");
}
