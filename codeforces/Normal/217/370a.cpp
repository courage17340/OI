#include <cstdio>
int x1,y1,x,y,a1,a2,a3;
inline int abs(int x){
	return (x > 0 ? x : -x);
}
inline int max(int a,int b){
	return (a > b ? a : b);
}
int main(){
	scanf("%d%d%d%d",&x1,&y1,&x,&y);
	x -= x1;
	y -= y1;
	if (x == 0 && y == 0) a1 = 0;else
		if (x * y == 0) a1 = 1;else a1 = 2;
	if ((x + y) & 1) a2 = 0;else
		if (abs(x) == abs(y)) a2 = 1;else a2 = 2;
	if (x == y && x == 0) a2 = 0;
	a3 = max(abs(x),abs(y));
	printf("%d %d %d\n",a1,a2,a3);
}
