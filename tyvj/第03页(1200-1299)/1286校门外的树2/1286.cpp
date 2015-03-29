#include <cstdio>
#include <algorithm>
int m,n,p,q,ans,l,r;
struct rec{int l,r;};
rec a[20010];
bool cmp(rec a,rec b){
	return a.l < b.l;
}
int main(){
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	std::sort(a + 1,a + n + 1,cmp);
	ans = m + 1;
	p = 1;
	while (p <= n){
		q = p;
		l = a[p].l;
		r = a[p].r;
		while (q < n && a[q + 1].l <= r){
			q++;
			if (r < a[q].r) r = a[q].r;
		}
		ans -= (r - l + 1);
		p = q + 1;
	}
	printf("%d\n",ans);
}
