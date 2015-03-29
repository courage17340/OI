#include <cstdio>
int gcd(int a,int b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if ((a + b) & 1 && gcd(a,b) == 1) printf("YES\n");else printf("IMPOSSIBLE\n");
}
