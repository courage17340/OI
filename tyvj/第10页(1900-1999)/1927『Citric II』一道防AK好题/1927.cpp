#include <cstdio>
typedef long long ll;
ll a[1000010],b[1000010][3],n,m,x,y,z,ans[1000010],A,B,C,D,E,I;
int main(){
	scanf("%lld",&n);
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	m = 0;
	while (scanf("%lld%lld%lld",&x,&y,&z) != EOF){
		m++;
		b[m][0] = x;
		b[m][1] = y;
		b[m][2] = z;
	}
	ans[m - 1] = - b[m][2];
	for (int i = m - 2;i >= 1;i--){
		I = ans[i + 1];
		x = b[i + 1][0];
		y = b[i + 1][1] + 1;
		z = b[i + 1][2] + I;
		A = (I + 1) * a[I] * a[I];
		B = I * a[I];
		ans[i] = -(A * x + B * y + z) / (A + B + 1);
	}
	for (int i = 1;i < m;i++) printf("%lld\n",ans[i]);
}
