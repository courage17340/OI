#include <cstdio>
int n,m,a[12],p;
int main(){
	while (1){
		scanf("%d",&n);
		m = n;
		if (!n) break;
		p = 0;
		while (n){
			a[++p] = n % 10;
			n /= 10;
			if (a[p] > 4) a[p]--;
		}
		for (int i = p;i >= 1;i--) n = n * 9 + a[i];
		printf("%d: %d\n",m,n);
	}
}