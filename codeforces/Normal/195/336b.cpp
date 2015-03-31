#include<cstdio>
#include<cmath>
int f[100010]={0},n,r;
long long a=0;
double x;
int main(){
	scanf("%d%d",&n,&r);
	if (n==1){
		x=2.0*r;
		printf("%.9llf\n",x);
		return 0;
	}
	if (n==2){
		x=(2.0+sqrt(2.0)/2)*r;
		printf("%.9llf\n",x);
		return 0;
	}
	x=sqrt(2.0)*2*(n-1)*(n-1)/n/n;
	a=(n*5-6)*2;
	for (int i=4;i<=n;i++) a+=(long long)2*(i-2)*(2*n-2*i+2);
	x=x+(double)a/n/n;
	printf("%.9llf\n",x*r);
}
