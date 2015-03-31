#include<cstdio>
#include<algorithm>
int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}
int n,a[110],ans,x;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	x=a[1];
	for (int i=2;i<=n;i++) x=gcd(x,a[i]);
	ans=a[n]/x-n;
	if (ans&1) printf("Alice");else printf("Bob");
}
