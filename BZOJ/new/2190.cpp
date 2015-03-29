#include <iostream>
using namespace std;
const int M = 40000;
int n,a[M + 10] = {0},b[M + 10];
long long ans;
int phi(int x){
	int ans = x,t;
	while (x > 1){
		t = a[x];
		ans -= ans / t;
		while (a[x] == t) x = b[x];
	}
	return ans;
}
int main(){
	cin >> n;
	for (int i = 2;i <= 200;i++)
		for (int j = i;j <= M;j += i) if (!a[j]) a[j] = i;
	for (int i = 1;i <= M;i++) if (!a[i]) a[i] = i;
	for (int i = 1;i <= M;i++) b[i] = i / a[i];
	ans = 1;
	for (int i = 1;i < n;i++) ans += 2 * phi(i);
	cout << ans << endl;
}
