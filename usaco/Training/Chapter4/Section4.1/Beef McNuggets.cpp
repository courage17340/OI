/*
USER: courage2
LANG:C++
TASK: nuggets
*/
#include <cstdio>
#include <cmath>
int n,x,a[11];
bool f[100010] = {0};
int gcd(int a,int b){
	return b ? gcd(b,a % b) : a;
}
int main(){
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	x = a[1];
	for (int i = 2;i <= n;i++) x = gcd(x,a[i]);
	if (x > 1){
		puts("0");
		return 0;
	}
	f[0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = a[i];j <= 100000;j++) f[j] |= f[j - a[i]];
	x = 100000;
	while (x >= 1 && f[x]) x--;
	printf("%d\n",x);
}
