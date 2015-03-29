/*
USER: courage2
LANG: C++
TASK: fact4
*/
#include <cstdio>
int n,k,x,ans = 1;
int main(){
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	scanf("%d",&n);
	k = 0;
	x = n;
	while (x){
		k += x / 5;
		x /= 5;
	}
	for (int i = 1;i <= n;i++){
		x = i;
		while (x % 5 == 0) x /= 5;
		if (x & 1) ans = ans * x % 10;else{
			while (k && (x & 1) == 0){
				k--;
				x >>= 1;
			}
			ans = ans * x % 10;
		}
	}
	printf("%d\n",ans);
}
