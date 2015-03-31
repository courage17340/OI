#include <cstdio>
int x,ans = 0;
int main(){
	scanf("%d",&x);
	ans = 1;
	for (int i = 2;i <= x;i++) ans += (i - 1) * 12;
	printf("%d\n",ans);
}
