#include <algorithm>
#include <cstdio>
double a[5000010];
int n;
bool equal(double a,double b){
	return a - b < 1e-3;
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%lf",a + i);
	std::sort(a + 1,a + n + 1);
	printf("%.2f",a[1]);
	for (int i = 2;i <= n;i++) if (!equal(a[i],a[i - 1])) printf(" %.2f",a[i]);
	printf("\n");
}
