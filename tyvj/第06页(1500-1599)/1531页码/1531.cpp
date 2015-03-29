#include <iostream>
using namespace std;
int n;
typedef long long ll;
ll f[10],ans = 0;
ll g(ll x,ll k){
	ll ans = 0;
	for (ll t = 1;t <= x;t *= 10){
		ans += (ll)(x / (t * 10)) * t;
		if (k == x / t % 10) ans += (x % t + 1);
		if (k < x / t % 10) ans += t;
	}
	return ans;
}
int main(){
	cin >> n;
	if (n == 1000000000){
		ans++;
		n--;
	}
	for (int i = 1;i <= 9;i++) f[i] = g(n,i);
	for (int i = 1;i <= 9;i++) ans += i * f[i];
	cout << ans << endl;
}
