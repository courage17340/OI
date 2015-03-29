#include <iostream>
using namespace std;
long long n,a[510],x;
char s[10];
int m,p,k;
int main(){
	cin >> n >> m;
	p = 0;
	for (int i = 1;i <= m;i++){
		cin >> s;
		if (s[0] == 'a')
			if (p == 0) cout << "F\n";else cout << "T\n";
		else if (s[0] == 'c')
			cout << p << "\n";
		else if (s[2] == 'n'){
			cin >> x;
			k = 0;
			for (int i = 1;i <= p;i++) if (a[i] == x) k = i;
			if (k) cout << "T\n";else cout <<"F\n";
		}else{
			cin >> x;
			k = 0;
			for (int i = 1;i <= p;i++) if (a[i] == x) k = i;
			if (k){
				for (int i = k;i < p;i++) a[i] = a[i + 1];
				p--;
			}else a[++p] = x;
		}
	}
}
