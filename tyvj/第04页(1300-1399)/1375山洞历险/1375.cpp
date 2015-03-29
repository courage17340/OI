#include <cstdio>
#include <cstring>
const int N = 1250,md = 1e8;
int n;
class num{
public:
int v[N + 1],p;
num(){
	memset(v,0,sizeof v);
	p = N;
}
num operator + (const num & a){
	num b;
	b.p = p;
	if (p > a.p) b.p = a.p;
	int t = 0;
	for (int i = N;i >= b.p;i--){
		b.v[i] = t + v[i] + a.v[i];
		t = b.v[i] / md;
		b.v[i] %= md;
	}
	while (t){
		b.v[--b.p] = t % md;
		t /= md;
	}
	return b;
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
int main(){
	scanf("%d",&n);
	num a;
	a.v[N] = 1;
	for (int i = 1;i <= n;i++) a = a + a;
	a.show();
	num b,c,t;
	b.v[N] = c.v[N] = 1;
	for (int i = 4;i <= n;i++){
		t = b + c;
		b = c;
		c = t;
	}
	c.show();
}
