#include<cstdio>
int m,n,t;
long long ans;
int main(){
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		scanf("%d%d",&n,&m);
		ans=(long long)(n+m)*(m-n+1)/2;
		printf("Scenario #%d:\n",i);
		printf("%lld\n\n",ans);
	}
}