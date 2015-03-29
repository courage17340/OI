#include <cstdio>
#include <cstring>
const int md = 100000;
int n;
class num{
public:
int v[11];
num(){
	memset(v,0,sizeof v);
}
num operator +(const num & a){
	num x;
	for (int i = 0;i < 11;i++) x.v[i] = v[i] + a.v[i];
	int k = 0;
	for (int i = 10;i >= 0;i--){
		x.v[i] += k;
		k = x.v[i] / md;
		x.v[i] %= md;
	}
	return x;
}
void out(int x){
	if (x < 1e4) printf("0");
	if (x < 1e3) printf("0");
	if (x < 100) printf("0");
	if (x < 10) printf("0");
	printf("%d",x);
}
void show(){
	int p = 0;
	while (v[p] == 0) p++;
	printf("%d",v[p]);
	for (int i = p + 1;i <= 10;i++) out(v[i]);
}
};
num f[110][3];
int main(){
	scanf("%d",&n);
	f[1][0].v[10] = f[1][1].v[10] = f[1][2].v[10] = 1;
	for (int i = 2;i <= n;i++){
		f[i][0] = f[i - 1][0] + f[i - 1][1] + f[i - 1][2];
		f[i][1] = f[i - 1][0] + f[i - 1][2];
		f[i][2] = f[i - 1][0] + f[i - 1][1];
	}
	(f[n][0] + f[n][1] + f[n][2]).show();
}
