#include <iostream>
#include <string>
using namespace std;
string s,t;
string f(string s,string t){
	int l = s.size();
	if (l <= 1) return s;
	int k = 0;
	while (t[k] != s[0]) k++;
	return f(s.substr(1,k),t.substr(0,k)) + f(s.substr(k + 1,l - k - 1),t.substr(k + 1,l - k - 1)) + s[0];
}
int main(){
	while (cin >> s >> t) cout << f(s,t) << "\n";
}