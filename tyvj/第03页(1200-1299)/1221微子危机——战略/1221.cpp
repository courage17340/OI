#include <cstdio>
#include <cstring>
int a[1010][1010],d[1010],n,m,k,x,y,z,p,ans;
bool v[1010] = {0},f;
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) a[i][j] = (i == j ? 0 : 1e8);
	while (k--){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y] = min(a[x][y],z);
		a[y][x] = a[x][y];
	}
	for (int i = 1;i <= n;i++) d[i] = a[m][i];
	v[m] = 1;
	d[0] = 1e9;
	for (int q = 2;q <= n;q++){
		p = 0;
		for (int i = 1;i <= n;i++) if (!v[i] && d[p] > d[i]) p = i;
		v[p] = 1;
		for (int i = 1;i <= n;i++) if (d[i] > d[p] + a[p][i]) d[i] = d[p] + a[p][i];
	}
	f = 1;
	for (int i = 1;i <= n;i++) if (d[i] >= 1e8) f = 0;
	if (f){
		ans = 0;
		for (int i = 1;i <= n;i++) ans += d[i];
		printf("%d M(s) are needed.",ans);
	}else printf("Sth wrong.");
}
