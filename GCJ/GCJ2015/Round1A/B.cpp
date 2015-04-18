#include <cstdio>
#include <algorithm>
typedef long long ll;
int t,n,m,a[1010],ans;
ll l,r,mid,num,tmp;
struct rec{int t,i;};
rec f[1010];
bool cmp(rec a,rec b){
	if (a.t != b.t) return a.t < b.t;
	return a.i < b.i;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;++i) scanf("%d",&a[i]);
		l = 0;
		r = (ll)a[1] * (m - 1);
		while (l < r){
			mid = (l + r) / 2;
			num = 0;
			for (int i = 1;i <= n;++i) num += mid / a[i];
			tmp = num + n;
			if (tmp >= m) r = mid;else l = mid + 1;
		}
		mid = (l + r) / 2;
		num = 0;
		for (int i = 1;i <= n;++i) num += mid / a[i];
		m -= num;
		for (int i = 1;i <= n;++i){
			f[i].t = -(mid % a[i]);
			f[i].i = i;
		}
		std::sort(f + 1,f + n + 1,cmp);
		ans = f[m].i;
		printf("Case #%d: %d\n",T,ans);
	}
}
