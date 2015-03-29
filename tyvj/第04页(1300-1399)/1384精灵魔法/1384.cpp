#include <cstdio>
#include <algorithm>
typedef long long ll;
int n,b[100010];
ll ans;
struct rec{int x,y;};
rec a[100010];
bool cmp(rec a,rec b){
	return a.y < b.y;
}
void merge(int l,int r){
	if (l == r) return;
	int m = (l + r) >> 1;
	merge(l,m);
	merge(m + 1,r);
	int p = l,q = m + 1,t = l - 1;
	while (p <= m && q <= r)
		if (a[p].x <= a[q].x) b[++t] = a[p++].x;else{
			ans += (m - p + 1);
			b[++t] = a[q++].x;
		}
	if (p <= m) for (int i = p;i <= m;i++) b[++t] = a[i].x;
	if (q <= r) for (int i = q;i <= r;i++) b[++t] = a[i].x;
	for (int i = l;i <= r;i++) a[i].x = b[i];
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i].y);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i].x);
	std::sort(a + 1,a + n + 1,cmp);
	merge(1,n);
	printf("%lld",ans);
}
