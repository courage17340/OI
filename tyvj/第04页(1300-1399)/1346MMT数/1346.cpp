#include<cstdio>
#include<cmath>
int n,ans,a[20][2],p,q,k;
int main(){
	scanf("%d",&n);
	p=0;
	k=(int)sqrt(n);
	ans=q=n;
	for (int i=2;i<=k;i++) if (n%i==0){
		p++;
		a[p][0]=i;
		a[p][1]=0;
		while (n%i==0){
			a[p][1]++;
			n/=i;
		}
	}
	if (n!=1){
		p++;
		a[p][0]=n;
		a[p][1]++;
	}
	n=q;
	for (int i=1;i<=p;i++) ans=ans-ans/a[i][0];
	ans=n-ans;
	k=1;
	for (int i=1;i<=p;i++) k*=(a[i][1]+1);
	ans-=k;
	ans++;
	printf("%d",ans);
}
