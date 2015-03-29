#include<cstdio>
int a,b,x,y,m,n,l,k;
int ex_gcd(int a,int b,int &x,int &y){
	if (b==0){
		x=1;
		y=0;
		return a;
	}
	int r=ex_gcd(b,a%b,x,y),t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
	a=m-n;
	b=y-x;
	if (a<0){
		a=-a;
		b=-b;
	}
	a%=l;
	b%=l;
	if (b<0) b+=l;
	k=gcd(a,l);
	if (b%k!=0){
		printf("Impossible");
		return 0;
	}
	a/=k;
	b/=k;
	l/=k;
	ex_gcd(a,l,x,y);
	x=(long long)x*b%l;
	if (x<0) x+=l;
	printf("%d",x);
}