#include<cstdio>
#include<cmath>
int x,i,j;
int main(){
	while (scanf("%d",&x)!=EOF){
		j=sqrt(2.0*x);
		j--;
		while ((j+1)*(j+2)<x*2) j++;
		i=x-j*(j+1)/2;
		if (j&1) printf("TERM %d IS %d/%d\n",x,i,j+2-i);else printf("TERM %d IS %d/%d\n",x,j+2-i,i);
	}
}