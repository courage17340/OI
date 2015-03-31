#include<cstdio>
int x,y,x1,y1,x2,y2;
int main(){
	scanf("%d%d",&x,&y);
	if (x>=0 && y>=0){
		x1=0;
		y1=x+y;
		x2=x+y;
		y2=0;
	}
	if (x>=0 && y<0){
		x1=0;
		y1=y-x;
		x2=x-y;
		y2=0;
	}
	if (x<0 && y>=0){
		x1=x-y;
		y1=0;
		x2=0;
		y2=y-x;
	}
	if (x<0 && y<0){
		x1=x+y;
		y1=0;
		x2=0;
		y2=x+y;
	}
	printf("%d %d %d %d\n",x1,y1,x2,y2);
}
