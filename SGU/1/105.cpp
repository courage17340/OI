#include <cstdio>
int n,ans;
int main(){
	scanf("%d",&n);
	ans = n / 3 * 2;
	if (n % 3 == 2) ans++;
	printf("%d\n",ans);
}
