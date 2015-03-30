#include <cstdio>
#include <cstring>
const int N = 310;
class num{
	int v[N + 1],p;
public:
	num(){
		memset(v,0,sizeof v);
	}
	void set(const char *s){
		memset(v,0,sizeof v);
		int l = strlen(s);
		for (int i = l - 1;i >= 0;i--) v[i - l + 1 + N] = s[i] - '0';
		p = N - l + 1;
	}
	num operator +(const num &x){
		num a;
		for (int i = 0;i <= N;i++) a.v[i] = v[i] + x.v[i];
		int t = 0;
		for (int i = N;i >= 0;i--){
			a.v[i] += t;
			t = a.v[i] / 10;
			a.v[i] %= 10;
		}
		a.p = 0;
		while (a.p < N && a.v[a.p] == 0) a.p++;
		return a;
	}
	num operator -(const num &x){
		num a;
		for (int i = 0;i <= N;i++) a.v[i] = v[i] - x.v[i];
		int t = 0;
		for (int i = N;i >= 0;i--){
			a.v[i] += t;
			t = 0;
			if (a.v[i] < 0){
				a.v[i] += 10;
				t--;
			}
		}
		a.p = 0;
		while (a.p < N && a.v[a.p] == 0) a.p++;
		return a;
	}
	void show(){
		for (int i = p;i <= N;i++) printf("%d", v[i]);
		puts("");
	}
};
char s[310],t[310];
num a,b;
int o,l,p,q;
int main(){
	scanf("%s",s);
	o = 1;
	l = strlen(s);
	p = q = 0;
	a.set("0");
	while (p < l){
		while (q < l && s[q] != '+' && s[q] != '-') q++;
		for (int i = p;i < q;i++) t[i - p] = s[i];
		t[q - p] = 0;
		b.set(t);
		if (o == 1) a = a + b;else a = a - b;
		if (q >= l) break;
		if (s[q] == '+') o = 1;else o = -1;
		p = q + 1;
		q = p;
	}
	a.show();
}
