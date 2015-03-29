#include <cstdio>
#include <cstring>
const int md = 1e8,N = 1600;
class num{
public:
int p,v[N + 1];
num(){
	p = N;
	memset(v,0,sizeof v);
}
num(const char * s){
	int l = strlen(s);
	memset(v,0,sizeof v);
	p = N;
	int k = 1,x = 0;
	for (int i = l - 1;i >= 0;i--){
		v[p] += (s[i] - '0') * k;
		x++;
		k *= 10;
		if (x == 8){
			x = 0;
			k = 1;
			p--;
		}
	}
	if (p < N && v[p] == 0) p++;
}
num(const num & a){
	p = a.p;
	for (int i = 0;i <= N;i++) v[i] = a.v[i];
}
bool operator <= (const num & a){
	if (p != a.p) return p > a.p;
	for (int i = p;i <= N;i++) if (v[i] != a.v[i]) return v[i] < a.v[i];
	return 1;
}
num operator + (const num & a){
	num b(a);
	if (b.p > p) b.p = p;
	int x = 0;
	for (int i = N;i >= b.p;i--){
		b.v[i] += x + v[i];
		x = b.v[i] / md;
		b.v[i] %= md;
	}
	if (x){
		b.v[--b.p] = x % md;
		x /= md;
	}
	return b;
}
num & operator = (const num & a){
	if (&a == this) return *this;
	p = a.p;
	for (int i = 0;i <= N;i++) v[i] = a.v[i];
	return *this;
}
void out(int x){
	if (x < 1e7) printf("0");
	if (x < 1e6) printf("0");
	if (x < 1e5) printf("0");
	if (x < 1e4) printf("0");
	if (x < 1e3) printf("0");
	if (x < 100) printf("0");
	if (x < 10) printf("0");
	printf("%d",x);
}
void show(){
	printf("%d",v[p]);
	for (int i = p + 1;i <= N;i++) out(v[i]);
	printf("\n");
}
};
num a[2],t;
char s[13000];
int p;
int main(){
	scanf("%s",s);
	num x(s);
	a[0].v[N] = a[1].v[N] = 1;
	p = 0;
	while (1){
		t = a[0] + a[1];
		if (t <= x){
			a[p] = t;
			p ^= 1;
		}else{
			a[p].show();
			a[p ^ 1].show();
			break;
		}
	}
}
