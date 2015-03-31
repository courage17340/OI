#include<cstdio>
#include<cmath>
#include<algorithm>
double a[4010],ans,x;
int n,p;
double min(double a,double b){
	return (a<b?a:b);
}
bool cmp(double a,double b){
	return (fabs(a-0.5)>fabs(b-0.5));
}
int main(){
	scanf("%d",&n);
	n<<=1;
	p=0;
	for (int i=1;i<=n;i++){
		scanf("%lf",&x);
		if (fabs(x-floor(x))<1e-6) continue;
		x-=floor(x);
		a[++p]=x;
	}
	ans=n/2;
	for (int i=1;i<=p;i++) ans-=a[i];
	n-=p;
	while (n>0 && ans>1){
		ans--;
		n--;
	}
	if (n && fabs(ans-1)<ans) ans=fabs(ans-1);
	printf("%.3f",fabs(ans));
}
