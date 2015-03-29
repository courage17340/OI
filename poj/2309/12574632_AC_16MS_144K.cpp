#include <cstdio>
int n,x,y,z;
int main(){
	scanf("%d",&n);
	while (n--){
		scanf("%d",&x);
		z = x;
		y = 1;
		while ((x & 1) == 0){
			x >>= 1;
			y <<= 1;
		}
		printf("%d %d\n",z - y + 1,z + y - 1);
	}
}