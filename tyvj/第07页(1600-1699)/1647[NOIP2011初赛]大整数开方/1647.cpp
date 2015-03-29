#include <cstdio>
#include <cstring>
const int N = 110;
char s[N + 1];
class num{
public:
int p,v[N + 1];
void set(const char * s){
	memset(v,0,sizeof v);
	int l = strlen(s);
	p = N + 1 - l;
	for (int i = l - 1;i >= 0;i--) v[i - l + N + 1] = s[i] - '0';
}
bool operator <(const num & a){
	if (p != a.p) return p > a.p;
	for (int i = p;i <= N;i++) if (v[i] != a.v[i]) return v[i] < a.v[i];
	return 0;
}
bool operator ==(const num & a){
	if (p != a.p) return 0;
	for (int i = p;i <= N;i++) if (v[i] != a.v[i]) return 0;
	return 1;
}
bool operator <=(const num & a){
	return (*this) < a || (*this) == a;
}
void make(){
	int x = 0;
	for (int i = N;i >= 0;i--){
		v[i] += x;
		x = v[i] / 10;
		v[i] %= 10;
	}
	p = 0;
	while (p < N && !v[p]) p++;
}
num operator *(const num & a){
	num b;
	b.set("0");
	for (int i = p;i <= N;i++)
		for (int j = a.p;j <= N;j++)
			b.v[i + j - N] += v[i] * a.v[j];
	b.make();
	return b;
}
num operator +(const num & a){
	num b;
	b.set("0");
	for (int i = 0;i <= N;i++) b.v[i] = v[i] + a.v[i];
	b.make();
	return b;
}
void show(){
	for (int i = p;i <= N;i++) printf("%d",v[i]);
	printf("\n");
}
num& operator =(const num & a){
	if (&a == this) return *this;
	p = a.p;
	for (int i = 0;i <= N;i++) v[i] = a.v[i];
	return *this;
}
num pre(){
	num a;
	for (int i = 0;i <= N;i++) a.v[i] = v[i];
	a.v[N]--;
	int x = N;
	while (a.v[x] < 0){
		a.v[x] += 10;
		--a.v[--x];
	}
	a.make();
	return a;
}
};
num half(const num & a){
	num b;
	b.set("0");
	int x = 0;
	for (int i = a.p;i <= N;i++){
		b.v[i] = x * 10 + a.v[i];
		x = b.v[i] & 1;
		b.v[i] >>= 1;
	}
	if (a.v[N] & 1) b.v[N]++;
	b.make();
	return b;
}
int main(){
	scanf("%s",s);
	num l,r,m,x,a;
	a.set(s);
	l.set("1");
	r.set(s);
	while (l < r){
		m = half(l + r);
		x = m * m;
		if (x == a){
			m.show();
			return 0;
		}
		if (x < a) l = m;else r = m.pre();
	}
	l.show();
}
