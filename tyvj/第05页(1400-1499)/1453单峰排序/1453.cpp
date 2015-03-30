#include <iostream>
using namespace std;
const int md = 1234567;
typedef long long ll;
ll n;
ll pow(ll n){
	if (n == 0) return 1;
	ll y = pow(n >> 1);
	y = y * y % md;
	if (n & 1) y <<= 1;
	return y % md;
}
int main(){
	cin >> n;
	cout << pow(n - 1) << endl;
}
