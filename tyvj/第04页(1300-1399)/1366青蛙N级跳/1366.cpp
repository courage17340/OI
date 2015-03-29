#include <cstdio>
typedef long long ll;
int a,b,n,m;
class mat{
public:
int v[2][2];
void set(int a,int b,int c,int d){
	v[0][0] = a;
	v[0][1] = b;
	v[1][0] = c;
	v[1][1] = d;
}
mat operator *(const mat & a){
	mat b;
	b.set(0,0,0,0);
	for (int i = 0;i < 2;i++)
		for (int j = 0;j < 2;j++)
			for (int k = 0;k < 2;k++) b.v[i][j] = ((ll)v[i][k] * a.v[k][j] + b.v[i][j]) % m;
	return b;
}
};
mat pow(int n){
	int f[40] = {0},p = 0;
	while (n){
		f[++p] = n & 1;
		n >>= 1;
	}
	mat x;
	x.set(a,1,0,1);
	mat y;
	y.set(1,0,0,1);
	for (int i = p;i >= 1;i--){
		y = y * y;
		if (f[i]) y = y * x;
	}
	return y;
}
int main(){
	scanf("%d%d%d%d",&a,&b,&n,&m);
	printf("%d",(ll)b * pow(n).v[0][1] % m);
}
