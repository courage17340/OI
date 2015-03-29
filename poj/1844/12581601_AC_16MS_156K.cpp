#include <cstdio>
#include <cmath>
int s,n;
int main(){
	scanf("%d",&s);
	n = sqrt(s * 2.0);
	while (n * (n + 1) / 2 < s) n++;
	while ((n * (n + 1) / 2 - s) & 1) n++;
	printf("%d",n);
}