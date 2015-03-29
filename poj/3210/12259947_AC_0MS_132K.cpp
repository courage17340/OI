#include<cstdio>
int n;
int main(){
	while (1){
		scanf("%d",&n);
		if (n==0) break;
		if (n&1) printf("%d\n",n-1);else printf("No Solution!\n");
	}
}