#include<cstdio>
const int md=1000000009;
int n,m,k,ans,p,q,a[40],r;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if (n/k+m<=n){
		printf("%d",m);
		return 0;
	}
	p=m-(n-n/k);
	q=m-p*k;
	ans=1;
	p+=1;
	r=0;
	while (p){
		r++;
		a[r]=p&1;
		p>>=1;
	}
	for (int i=r;i>=1;i--){
		ans=(long long)ans*ans%md;
		if (a[i]) ans=(long long)ans*2%md;
	}
	ans-=2;
	if (ans<0) ans+=md;
	ans=(long long)ans*k%md;
	ans=((long long)ans+q)%md;
	printf("%d",ans);
}
