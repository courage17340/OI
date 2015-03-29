#include <iostream>
using namespace std;
typedef long long ll;
ll a,b,c;
int main(){
	while (1){
		cin >> a >> b;
		if (a + b == 0) break;
		a += b;
		if (b > a - b) b = a - b;
		c = 1;
		for (int i = 1;i <= b;i++) c = c * (a + 1 - i) / i;
		cout << c << "\n";
	}
}