#include <cstdio>
int t,n,a[1010],ans1,ans2,r;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%d",&n);
		for (int i = 1;i <= n;++i) scanf("%d",&a[i]);
		ans1 = 0;
		for (int i = 2;i <= n;++i) if (a[i] < a[i - 1]) ans1 += a[i - 1] - a[i];
		ans2 = 0;
		r = 0;
		for (int i = 2;i <= n;++i){
			if (a[i] >= a[i - 1]) continue;
			int tmp = a[i - 1] - a[i];
			if (r < tmp) r = tmp;
		}
		for (int i = 1;i < n;++i){
			int tmp = r;
			if (tmp > a[i]) tmp = a[i];
			ans2 += tmp;
		}
		printf("Case #%d: %d %d\n",T,ans1,ans2);
	}
}
