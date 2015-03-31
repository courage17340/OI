#include<cstdio>
int a,b,c,d,e,f,g;
int gcd(int x,int y){
	if (y==0) return x;
	return gcd(y,x%y);
}
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (a*d>=b*c){
		e=a*d-b*c;
		f=a*d;
		g=gcd(e,f);
		e/=g;
		f/=g;
		printf("%d/%d",e,f);
	}else{
		e=b*c-a*d;
		f=b*c;
		g=gcd(e,f);
		e/=g;
		f/=g;
		printf("%d/%d",e,f);
	}
}
