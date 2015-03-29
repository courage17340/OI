#include <cstdio>
#include <cmath>
const double k1 = 6.11,k2 = 5417.7530,k3 = 273.16,k4 = 10.0,k5 = 0.5555;
double t,d,h;
char s[3];
int main(){
	while (1){
		scanf("%s",s);
		if (s[0] == 'E') break;
		t = d = h = -1e7;
		if (s[0] == 'T') scanf("%lf",&t);else if (s[0] == 'D') scanf("%lf",&d);else scanf("%lf",&h);
		scanf("%s",s);
		if (s[0] == 'T') scanf("%lf",&t);else if (s[0] == 'D') scanf("%lf",&d);else scanf("%lf",&h);
		if (h < -1e6) h = k5 * (k1 * exp(k2 * (1.0 / k3 - 1.0 / (d + k3))) - k4) + t;
		if (d < -1e6) d = 1.0 / (1.0 / k3 - log(((h - t) / k5 + k4) / k1) / k2) - k3;
		if (t < -1e6) t = h - k5 * (k1 * exp(k2 * (1.0 / k3 - 1.0 / (d + k3))) - k4);
		printf("T %.1f D %.1f H %.1f\n",t,d,h);
	}
}