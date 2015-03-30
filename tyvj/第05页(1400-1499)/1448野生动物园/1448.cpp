#include <cstdio>
#include <algorithm>
const int N = 10000010;
int b[100010],n,m,k,x,y,z,ll[N],rr[N],lp[N],rp[N],f[N] = {0},g[100010];
struct rec{int x,i;};
rec a[100010];
bool cmp(rec a,rec b){
	return a.x < b.x;
}
int build(int l,int r){
	k++;
	int t = k;
	ll[t] = l;
	rr[t] = r;
	if (l == r) return t;
	int m = (l + r) >> 1;
	lp[t] = build(l,m);
	rp[t] = build(m + 1,r);
	return t;
}
int add(int p,int x){
	k++;
	int t = k;
	ll[t] = ll[p];
	rr[t] = rr[p];
	f[t] = f[p] + 1;
	if (ll[t] == rr[t]) return t;
	int m = (ll[t] + rr[t]) >> 1;
	if (x > m){
		lp[t] = lp[p];
		rp[t] = add(rp[p],x);
	}else{
		lp[t] = add(lp[p],x);
		rp[t] = rp[p];
	}
	return t;
}
int find(int p,int q,int x){
	if (ll[p] == rr[p]) return a[ll[p]].x;
	int t = f[lp[q]] - f[lp[p]];
	if (t >= x) return find(lp[p],lp[q],x);
	return find(rp[p],rp[q],x - t);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) a[i].i = i;
	for (int i = 1;i <= n;i++) scanf("%d",&a[i].x);
	std::sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++) b[a[i].i] = i;
	k = 0;
	g[0] = build(1,n);
	for (int i = 1;i <= n;i++) g[i] = add(g[i - 1],b[i]);
	while (m--){
		scanf("%d%d%d",&x,&y,&z);
		printf("%d\n",find(g[x - 1],g[y],z));
	}
}
