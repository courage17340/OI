#include<cstdio>
int n,k,x,p,q;
long long a[201000]={0},f[201000]={0},g[201000]={0},ans=0;
inline long long max(long long a,long long b){
	return (a>b?a:b);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=a[i-1]+(long long)x;
	}
	ans=0;
	for (int i=k;i<=n-k+1;i++)
		f[i]=max(f[i-1],a[i]-a[i-k]);
	for (int i=n-k+1;i>=k;i--)
		g[i]=max(g[i+1],a[i+k-1]-a[i-1]);
	for (int i=k;i<=n-k+1;i++) if (ans<f[i]+g[i+1]){
		ans=f[i]+g[i+1];
		p=i;
	}
	q=p+1;
	for (int i=k;i<=p;i++) if (f[i]==f[p]){
		p=i;
		break;
	}
	p=p-k+1;
	for (int i=q;i<=n-k+1;i++) if (a[i+k-1]-a[i-1]==g[q]){
		q=i;
		break;
	}
	printf("%d %d\n",p,q);
}
