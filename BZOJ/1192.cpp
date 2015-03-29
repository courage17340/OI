#include<cstdio>
int n;
int f(int x){
	int y=1;
	int k=1;
	x-=y;
	while (x){
		y*=2;
		if (x<y) y=x;
		x-=y;
		k++;
	}
	return k;
}
int main(){
	scanf("%d",&n);
	printf("%d",f(n));
}
