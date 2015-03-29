#include<cstdio>
int f[16]={0},n;
int main(){
	f[0]=1;
	f[1]=3;
	for (int i=2;i<=15;i++) f[i]=f[i-1]*4-f[i-2];
	while (1){
		scanf("%d",&n);
		if (n==-1) break;
		if (n&1){
			printf("0\n");
			continue;
		}
		printf("%d\n",f[n/2]);
	}
}