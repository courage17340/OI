#include <cstdio>
#include <cmath>
double l,n,c,k,p,q,m;
int main(){
	while (1){
		scanf("%lf%lf%lf",&l,&n,&c);
		if (l < 0) break;
		k = 1.0 / (n * c + 1);
		if (fabs(k - 1) < 1e-5){
			printf("0.000\n");
			continue;
		}
		p = 1e-5;
		q = atan(1.0) * 2;
		while (q - p > 1e-8){
			m = (p + q) / 2;
			if (sin(m) / m < k) q = m;else p = m;
		}
		printf("%.3f\n",l * (1 - cos(p)) / 2 / p / k);
	}
}