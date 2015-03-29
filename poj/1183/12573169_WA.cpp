#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int a;
ll b,ans;
int main(){
	cin >> a;
	if (a == 1){
		cout << 5;
		return 0;
	}
	b = (ll)a * a - 1;
	int k = sqrt(1.0 * b);
	if ((ll)k * k < b) k++;
	while (b % k) k--;
	cout << 2 * a + k + b / k;
}