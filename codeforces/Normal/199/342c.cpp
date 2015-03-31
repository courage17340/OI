#include<cstdio>
#include<cmath>
int r,h,p,q,ans;
int main(){
	scanf("%d%d",&r,&h);
	p=h/r;
	q=h%r;
	if ((long long)q*q*4>=(long long)r*r*3) ans=2*p+3;
		else if (q*2>=r) ans=2*p+2;else ans=p*2+1;
	printf("%d",ans);
}
