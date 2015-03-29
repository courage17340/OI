#include<cstdio>
typedef long long ll;
int n,l,r,k;
ll ans=0;
int main(){
	scanf("%d%d",&n,&k);
	if (k==1){
		printf("%d\n",n-1);
		return 0;
	}
	if ((ll)n*n<=k){
		for (int i=1;i<=n;i++) ans+=(k%i);
		printf("%lld\n",ans);
		return 0;
	}
	if (n>k){
		ans+=ll(n-k)*k;
		n=k;
	}
	r=0;
	l=n+1;
	while (l!=r && l>0){
		r=l-1;
		l=k/(k/r+1)+1;
		ans+=(ll)(k%l+k%r)*(r-l+1)/2;
	}
	for (int i=1;i<r;i++) ans+=k%i;
	printf("%lld",ans);
}