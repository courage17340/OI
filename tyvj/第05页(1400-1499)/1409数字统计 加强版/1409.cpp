#include <iostream>
using namespace std;
typedef long long ll;
ll n,m;
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
	cin >> m >> n;
	cout << g(n,2) - g(m - 1,2) << endl;
}
