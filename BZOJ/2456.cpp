#include <cstdio>
int n,a,x,k;
int main(){
	scanf("%d",&n);
	k = 0;
	while (n--){
		scanf("%d",&x);
		if (k == 0){
			a = x;
			k = 1;
			continue;
		}
		if (a == x) ++k;else --k;
	}
	printf("%d\n",a);
}
