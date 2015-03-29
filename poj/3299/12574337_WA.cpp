#include <cstdio>
#include <cmath>
double t,d,e,h;
char s[3];
int main(){
	while (1){
		scanf("%s",s);
		if (s[0] == 'E') break;
		scanf("%lf D %lf",&t,&d);
		e = 6.11 * exp(5417.7530 * ((1.0 / 273.16) - (1.0 / (d + 273.16))));
		h = 0.5555 * (e - 10.0) + t;
		printf("T %.1f D %.1f H %.1f\n",t,d,h);
	}
}