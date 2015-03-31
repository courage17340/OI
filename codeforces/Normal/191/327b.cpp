#include<cstdio>
int n;
int main(){
	scanf("%d",&n);
	for (int i=1000000;i<n+999999;i++) printf("%d ",i);
	printf("%d\n",n+999999);
}
