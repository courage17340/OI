#include<cstdio>
char s[17]="0123456789abcdef";
int x,y,z,r,a[10];
int main(){
	scanf("%x,%d,%d",&r,&x,&y);
	r=(((r>>x)|0)<<x)|r;
	r=(((r>>y)|1)<<y)|r;
	y--;
	r=(((r>>y)|1)<<y)|r;
	y--;
	r=(((r>>y)|0)<<y)|r;
	x=-1;
	while (r){
		x++;
		a[x]=r&15;
		r>>=4;
	}
	for (int i=x;i>=0;i--) printf("%c",s[a[i]]);
	printf("\n");
}