#include <cstdio>
const int md = 123456;
int n,f[210] = {0},p,ans;
bool pr(int x){
	for (int i = 2;i * i <= x;i++) if (x % i == 0) return 0;
	return 1;
}
void make(int x,int flag){
	int y;
	for (int i = 2;i <= x;i++) if (pr(i)){
		y = x;
		while (y){
			y /= i;
			f[i] += y * flag;
		}
	}
}
int main(){
	scanf("%d",&n);
	make(n * 2,1);
	make(n + 1,-1);
	make(n,-1);
	ans = 1;
	for (int i = 2;i <= n * 2;i++) if (f[i]) while (f[i]--) ans = ans * i % md;
	printf("%d",ans);
}
