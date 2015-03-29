#include <cstdio>
int n,f[50],a[101] = {0},p,q,x;
int main(){
	scanf("%d",&n);
	if (n < 5){
		printf("%d",n);
		return 0;
	}
	q = 0;
	while ((q + 1) * (q + 4) / 2 <= n) q++;
	for (int i = 1;i <= q;i++) f[i] = i + 1;
	n -= q * (q + 3) / 2;
	p = q;
	while (n--){
		f[p--]++;
		if (p == 0) p = q;
	}
	a[100] = 1;
	p = 100;
	for (int i = 1;i <= q;i++){
		for (int j = p;j <= 100;j++) a[j] *= f[i];
		x = 0;
		for (int j = 100;j >= p;j--){
			a[j] += x;
			x = a[j] / 10;
			a[j] %= 10;
		}
		while (x){
			a[--p] = x % 10;
			x /= 10;
		}
	}
	for (int i = p;i <= 100;i++) printf("%d",a[i]);
}
