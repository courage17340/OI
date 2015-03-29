#include <cstdio>
int t,n,max,min,x;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		scanf("%d",&min);
		max = min;
		for (int i = 2;i <= n;i++){
			scanf("%d",&x);
			if (x < min) min = x;
			if (x > max) max = x;
		}
		printf("%d\n",(max - min) * 2);
	}
}