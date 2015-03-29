#include <cstdio>
const int md = 100003;
typedef long long ll;
ll n;
int m,ans,a,b;
int pow(int a,ll b){
	int f[70] = {0},p = 0;
	while (b){
		f[++p] = b & 1;
		b >>= 1;
	}
	int ans = 1;
	for (int i = p;i >= 1;i--){
		ans = (ll)ans * ans % md;
		if (f[i]) ans = (ll)ans * a % md;
	}
	return ans;
}
int main(){
	scanf("%d%lld",&m,&n);
	a = pow(m,n - 1);
	b = pow(m - 1,n - 1);
	a = (ll)(a - b) * m % md;
	if (a < 0) a += md;
	printf("%d\n",a);
}
