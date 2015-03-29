#include <iostream>
typedef unsigned long long ull;
using namespace std;
ull n;
int f(ull n){
	int x = 0;
	while (!(n & 1)){
		n >>= 1;
		x++;
	}
	return x;
}
int main(){
	while (cin >> n) cout << f(n) << endl;
}
