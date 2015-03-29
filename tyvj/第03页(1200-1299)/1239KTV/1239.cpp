#include <cstdio>
#include <cstring>
int n,a[110][3],w[110],ans;
bool v[10];
int f(int x,int y,int z){
	memset(v,0,sizeof v);
	v[a[x][0]] = v[a[x][1]] = v[a[x][2]] = 1;
	v[a[y][0]] = v[a[y][1]] = v[a[y][2]] = 1;
	v[a[z][0]] = v[a[z][1]] = v[a[z][2]] = 1;
	int t = 0;
	for (int i = 1;i <= 9;i++) t += v[i];
	if (t < 9) return -1;
	return w[x] + w[y] + w[z];
}
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	ans = -1;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&w[i]);
	for (int i = 1;i <= n - 2;i++)
		for (int j = i + 1;j <= n - 1;j++)
			for (int k = j + 1;k <= n;k++) ans = max(ans,f(i,j,k));
	if (ans < 0) printf("Impossible");else printf("%d",ans);
}
