#include <cstdio>
const int md = 1000000007;
typedef long long ll;
int n,x,ans;
int main(){
	scanf("%d",&n);
	x = 1;
	ans = 1;
	for (int i = n;i >= 3;i--){
		x = (ll)x * (-i) % md;
		ans = (ans + x) % md;
	}
	if (n & 1) ans = -ans;
	ans %= md;
	if (ans < 0) ans += md;
	printf("%d\n",ans);
}
