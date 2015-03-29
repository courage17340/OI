#include<cstdio>
#include<cmath>
int n,m;
int main(){
	scanf("%d",&n);
	m=(int)sqrt(n);
	for (int i=2;i<=m;i++) if (n%i==0){
		printf("%d",n/i);
		return 0;
	}
}
