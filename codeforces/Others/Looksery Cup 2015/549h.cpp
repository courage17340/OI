#include <cstdio>
#include <cmath>
typedef long long ll;
int A,B,C,D;
ll a,b,c,d,p,q,r;
double ans,t,t1,del;
double Abs(double x){
	return x > 0 ? x : -x;	
}
int main(){
	scanf("%d%d%d%d",&A,&B,&C,&D);
	a = A;
	b = B;
	c = C;
	d = D;
	ans = 1e10;
	for (int i = -1;i <= 1;i += 2)
		for (int j = -1;j <= 1;j += 2)
			for (int k = -1;k <= 1;k += 2)
				for (int l = -1;l <= 1;l += 2){
					t = 1e10;
					if (i * l == k * j){
						p = i * d + l * a - k * b - j * c;
						q = a * d - c * b;
						if (p != 0) t = Abs((double)q / p);
					}else{
						p = i * l - k * j;
						q = i * d + l * a - k * b - j * c;
						r = a * d - c * b;
						del = (double)q * q - 4 * p * (double)r;
						if (del >= 0){
							t = Abs((-q + sqrt(del)) / 2 / p);
							t1 = Abs((-q - sqrt(del)) / 2 / p);
							if (t > t1) t = t1;
						}
					}
					if (ans > t) ans = t;
				}
	printf("%.10f\n",ans);
}
