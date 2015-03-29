#include <cstdio>
int f[100010] = {0},a[11][11] = {{0}},x,y,n,m,k;
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	scanf("%d%d",&n,&m);
	while (n--){
		scanf("%d%d",&x,&y);
		a[x][y]++;
	}
	for (int i = 1;i <= 10;i++)
		for (int j = 1;j <= 10;j++){
			k = 1;
			while (a[i][j]){
				if (k > a[i][j]) k = a[i][j];
				a[i][j] -= k;
				x = i * k;
				y = j * k;
				for (int p = m;p >= x;p--) f[p] = max(f[p],f[p - x] + y);
				k <<= 1;
			}
		}
	printf("%d\n",f[m]);
}
