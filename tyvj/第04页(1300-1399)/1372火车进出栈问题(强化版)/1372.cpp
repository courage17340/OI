#include <cstdio>
typedef long long ll;
const ll md = 1e12;
int n,f[100010],p;
ll a[10001],k;
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
void out(ll x){
	ll y = 0;
	for (int i = 1;i <= 12;i++){
		y = y * 10 + x % 10;
		x /= 10;
	}
	for (int i = 1;i <= 12;i++){
		printf("%d",y % 10);
		y /= 10;
	}
}
int main(){
	scanf("%d",&n);
	p = 10000;
	a[p] = 1;
	make(n * 2,1);
	make(n + 1,-1);
	make(n,-1);
	for (int i = 2;i <= n * 2;i++) if (f[i]) while (f[i]--){
		k = 0;
		for (int j = 10000;j >= p;j--){
			a[j] = a[j] * i + k;
			k = a[j] / md;
			a[j] %= md;
		}
		while (k){
			a[--p] = k % md;
			k /= md;
		}
	}
	printf("%lld",a[p]);
	for (int i = p + 1;i <= 10000;i++) out(a[i]);
}
