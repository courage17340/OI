#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int a;
ll b,ans;
int main(){
	cin >> a;
	b = (ll)a * a + 1;
	int k = sqrt(1.0 * b);
	if ((ll)k * k < b) k++;
	while (b % k) k--;
	cout << 2 * a + k + b / k;
}