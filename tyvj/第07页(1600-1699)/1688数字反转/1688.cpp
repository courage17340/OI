#include <cstdio>
int x,y;
int main(){
	scanf("%d",&x);
	if (x < 0){
		printf("-");
		x = -x;
	}
	y = 0;
	while (x){
		y = y * 10 + x % 10;
		x /= 10;
	}
	printf("%d\n",y);
}
