#include <cstdio>
int a,b,c,d,e,f,x,y,k;
int main(){
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	k = a * e - b * d;
	x = c * e - b * f;
	y = a * f - c * d;
	if (k != 0) printf("x=%.2f\ny=%.2f\n",(double)x / k,(double)y / k);
		else if (x != 0 || y != 0) printf("No answer\n");
			else printf("Too many\n");
}
