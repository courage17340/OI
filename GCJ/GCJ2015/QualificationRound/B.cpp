#include <cstdio>
int t,n,m,l,r,mid,ans,x,a[1010];
int Min(int a,int b){
	return a < b ? a : b;
}
int f(int x){
	int ret = 0;
	for (int i = 1;i <= n;++i){
		ret += a[i] / x;
		if (a[i] % x == 0) --ret;
	}
	ret += x;
	return ret;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	
	for (int T = 1;T <= t;++T){
		scanf("%d",&n);
		m = 0;
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			if (m < a[i]) m = a[i];
		}
		ans = 1e9;
		for (int i = 1;i <= m;++i) ans = Min(ans,f(i));
		printf("Case #%d: %d\n",T,ans);
	}
}
