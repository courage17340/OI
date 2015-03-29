#include<cstdio>
#include<algorithm>
int n,a[10010],i,j;
long long ans;
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	i=1;
	j=n;
	ans=0;
	while (i<=j){
		ans=(long long)ans+(long long)(j-i)*(a[j]-a[i]);
		i++;
		j--;
	}
	ans=(long long)ans*2;
	printf("%lld\n",ans);
}