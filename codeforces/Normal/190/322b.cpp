#include<cstdio>
int a,b,c,ans,x;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	ans=a/3+b/3+c/3;
	a--;
	b--;
	c--;
	if (a>=0 && b>=0 && c>=0) x=1+a/3+b/3+c/3;
	if (ans<x) ans=x;
	a--;
	b--;
	c--;
	if (a>=0 && b>=0 && c>=0) x=2+a/3+b/3+c/3;
	if (ans<x) ans=x;
	printf("%d",ans);
}
