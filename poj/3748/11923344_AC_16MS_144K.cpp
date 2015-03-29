#include<cstdio>
int x,y,z,r,a[10];
int main(){
	scanf("%x,%d,%d",&r,&x,&y);
	r=r&(~(1<<x));
	r=r|(1<<y);
	y--;
	r=r|(1<<y);
	y--;
	r=r&(~(1<<y));
	printf("%x\n",r);
}