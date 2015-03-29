#include<cstdio>
int x,y,m,n,l,a,b;
long long ans;
int gcd(int x,int y){
	if (y==0) return x;
	return gcd(y,x%y);
}
long long f(int a,int b){
	a%=b;
	int d=b-a;
	if (d==1) return a;
	return (((long long)b*f(a,d)-1)/d);
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
	while (b<0) b+=l;
	if (b%gcd(a,l)){
		printf("Impossible\n");
		return 0;
	}
	ans=f(a,l)*b%l;
	printf("%lld\n",ans);
}