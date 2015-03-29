#include <cstdio>
const int N = 10000;
int f[20010] = {0},n,m,a[N + 1] = {0},q;
bool p(int x){
	for (int i = 2;i * i <= x;i++) if (x % i == 0) return 0;
	return 1;
}
void g(int x,int flag){
	int y;
	for (int i = 2;i <= x;i++) if (p(i)){
		y = x;
		while (y){
			y /= i;
			f[i] += y * flag;
		}
	}
}
void work(int n,int m){
	int k;
	g(n,1);
	g(m,-1);
	g(n - m,-1);
	for (int i = 2;i <= 20000;i++) while (f[i]--){
		for (int j = q;j <= N;j++) a[j] *= i;
		k = 0;
		for (int j = N;j >= q;j--){
			a[j] += k;
			k = a[j] / 10;
			a[j] %= 10;
		}
		while (k){
			a[--q] = k % 10;
			k /= 10;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	if (n + m <= 3){
		printf("1");
		return 0;
	}
	q = N;
	a[q] = 1;
	work(n + m - 2,m - 1);
	for (int i = q;i <= N;i++) printf("%d",a[i]);
}
