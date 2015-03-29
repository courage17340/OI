#include <cstdio>
#include <cmath>
int p,n,a,b,c,d,x;
int gcd(int a,int b){
	if (b == 0) return a;
	return gcd(b,a % b);
}
bool cmp(int a,int b,int c,int d){
	return a * d < b * c;
}
int main(){
	scanf("%d%d",&p,&n);
	a = 0;
	b = d = 1;
	c = p;
	for (int i = 1;i <= n;i++){
		x = sqrt(p * 1.0) * i;
		if (x * x > (long long)p * i * i) x--;
		if ((x + 1) * (x + 1) <= (long long)p * i * i) x++;
		if (x > n) break;
		if (!cmp(x,i,a,b)){
			a = x;
			b = i;
		}
		if (x < n && cmp(x + 1,i,c,d)){
			c = x + 1;
			d = i;
		}
	}
	x = gcd(a,b);
	a /= x;
	b /= x;
	x = gcd(c,d);
	c /= x;
	d /= x;
	printf("%d/%d %d/%d\n",a,b,c,d);
}
