#include<cstdio>
int n,x;
long long ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		ans=(long long)(x)*(x+1)*(x+2)*(x+3)/8;
		printf("%d %d %lld\n",i,x,ans);
	}
}