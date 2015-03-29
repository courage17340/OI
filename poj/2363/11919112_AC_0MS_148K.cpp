#include<cstdio>
int f[1010],t,x;
int main(){
	for (int i=1;i<=1000;i++) f[i]=100000000;
	for (int i=1;i<=1000;i++)
		for (int j=1;j<=1000/i;j++)
			for (int k=1;k<=1000/i/j;k++)
				if (f[i*j*k]>(i*j+j*k+k*i)*2) f[i*j*k]=(i*j+j*k+k*i)*2;
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		scanf("%d",&x);
		printf("%d\n",f[x]);
	}
}