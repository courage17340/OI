#include<cstdio>
int x,y,a,b,ans;
int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int main(){
	scanf("%d%d%d%d",&x,&y,&a,&b);
	x=lcm(x,y);
	a--;
	a/=x;
	b/=x;
	printf("%d",b-a);
}
