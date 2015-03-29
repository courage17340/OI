#include <cstdio>
#include <cstring>
typedef long long ll;
int n,k,f[1300],ans;
bool p(int x){
	for (int i = 2;i * i <= x;i++) if (x % i == 0) return 0;
	return 1;
}
void work(int x,int flag){
	int y;
	for (int i = 2;i <= x;i++) if (p(i)){
		y = x;
		while (y){
			y /= i;
			f[i] += y * flag;
		}
	}
}
int main(){
	while (1){
		scanf("%d%d",&n,&k);
		if (!n) break;
		if (n - k <= k) k = n - k;
		if (k == 0) printf("1\n");else
		if (k == 1) printf("%d\n",n);else
		if (k == 2) printf("%d\n",(ll)n * (n - 1) / 2);else{
			memset(f,0,sizeof f);
			work(n,1);
			work(n - k,-1);
			work(k,-1);
			ans = 1;
			for (int i = 2;i <= n;i++) while (f[i]--) ans *= i;
			printf("%d\n",ans);
		}
	}
}