#include<cstdio>
bool f(int x){
	int p,q=0,s=0,r=0;
	p=x;
	while (p>0){
		q+=p%10;
		p/=10;
	}
	p=x;
	while (p>0){
		s+=p%12;
		p/=12;
	}
	p=x;
	while (p>0){
		r+=p%16;
		p/=16;
	}
	return (q==s && s==r);
}
int main(){
	for (int i=2992;i<=9999;i++)
		if (f(i)) printf("%d\n",i);
}