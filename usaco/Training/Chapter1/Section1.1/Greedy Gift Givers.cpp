/*
USER: courage2
LANG: C++
TASK: gift1
*/
#include <fstream>
#include <string>
using namespace std;
struct rec{
	string name;
	int m1,m2;
};
int n,m;
rec a[11];
string s;
int f(string s){
	for (int i = 1;i <= n;i++) if (a[i].name == s) return i;
}
int main(){
	ifstream in("gift1.in");
	ofstream out("gift1.out");
	in >> n;
	for (int i = 1;i <= n;i++) in >> a[i].name;
	for (int i = 1;i <= n;i++) a[i].m2 = 0;
	for (int i = 1;i <= n;i++){
		in >> s;
		int j = f(s);
		in >> a[j].m1 >> m;
		if (!m) continue;
		for (int k = 1;k <= m;k++){
			in >> s;
			a[f(s)].m2 += a[j].m1 / m;
		}
		a[j].m2 -= a[j].m1 / m * m;
	}
	for (int i = 1;i <= n;i++) out << a[i].name << " " << a[i].m2 << "\n";
	in.close();
	out.close();
}
