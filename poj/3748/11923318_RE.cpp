#include<cstdio>
char s[17]="0123456789abcdef";
int x,y,z,r,a[10];
int main(){
	scanf("%x,%d,%d",&r,&x,&y);
	r=r&(~(1<<x));
	r=r|(1<<y);
	y--;
	r=r|(1<<y);
	y--;
	r=r&(~(1<<y));
	x=-1;
	while (r){
		x++;
		a[x]=r&15;
		r>>=4;
	}
	for (int i=x;i>=0;i--) printf("%c",s[a[i]]);
	printf("\n");
}