#include <cstdio>
int n,m,a[1010],f[1010] = {0};
bool p(int x){
	for (int i = 2;i * i <= x;i++) if (x % i == 0) return 0;
	return 1;
}
int pow(int a,int n){
	int y = 1,g[30] = {0},p = 0;
	while (n){
		g[++p] = n & 1;
		n >>= 1;
	}
	for (int i = p;i >= 1;i--){
		y = y * y % 2011;
		if (g[i]) y = y * a % 2011;
	}
	return y;
}
int main(){
	scanf("%d",&n);
	m = 0;
	for (int i = 2;i <= n;i++) if (p(i)) a[++m] = i;
	f[0] = 1;
	for (int i = 1;i <= m;i++)
		for (int j = a[i];j <= n;j++) f[j] = (f[j] + f[j - a[i]]) % 2010;
	printf("%d",pow(2,f[n]));
}
