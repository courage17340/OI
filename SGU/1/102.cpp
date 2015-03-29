#include <cstdio>
int n;
int phi(int x){
	int ret = x;
	for (int i = 2;i <= x;i++) if (x % i == 0){
		while (x % i == 0) x /= i;
		ret -= ret / i;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	printf("%d\n",phi(n));
}
