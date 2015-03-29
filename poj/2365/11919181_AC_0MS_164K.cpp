#include<cstdio>
#include<cmath>
struct rec{double x,y;};
rec a[101];
double r,ans=0;
const double pi=3.141592654;
double sqr(double x){
	return (x*x);
}
int n;
int main(){
	scanf("%d %lf",&n,&r);
	for (int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	for (int i=1;i<n;i++) ans+=sqrt(sqr(a[i].x-a[i+1].x)+sqr(a[i].y-a[i+1].y));
	ans+=sqrt(sqr(a[1].x-a[n].x)+sqr(a[1].y-a[n].y));
	ans+=2*pi*r;
	printf("%.2lf\n",ans);
}