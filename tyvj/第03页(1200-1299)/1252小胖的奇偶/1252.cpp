#include <cstdio>
#include <algorithm>
int n,l,f[20010],g[20010],p,q,k,rank[20010] = {0};
struct rec{int l,r,x;};
rec a[10010];
char s[10];
int h(int x){
	int l = 1,r = n * 2,m;
	while (f[l] != f[r]){
		m = (l + r) >> 1;
		if (f[m] == x) return g[m];
		if (f[m] < x) l = m + 1;else r = m - 1;
	}
	return g[l];
}
int father(int x){
	if (f[x] == x) return x;
	int y = father(f[x]);
	rank[x] ^= rank[f[x]];
	f[x] = y;
	return y;
}
int main(){
	scanf("%d%d",&l,&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d%s",&a[i].l,&a[i].r,s);
		a[i].l--;
		f[i * 2 - 1] = a[i].l;
		f[i * 2] = a[i].r;
		if (s[0] == 'e') a[i].x = 0;else a[i].x = 1;
	}
	std::sort(f + 1,f + n * 2 + 1);
	p = 1;
	k = 0;
	while (p <= n * 2){
		q = p;
		while (q < n * 2 && f[q + 1] == g[p]) q++;
		k++;
		for (int i = p;i <= q;i++) g[i] = k;
		p = q + 1;
	}
	for (int i = 1;i <= n;i++) a[i].l = h(a[i].l);
	for (int i = 1;i <= n;i++) a[i].r = h(a[i].r);
	for (int i = 1;i <= n * 2;i++) f[i] = i;
	for (int i = 1;i <= n;i++){
		if (father(a[i].l) == father(a[i].r) && rank[a[i].l] ^ rank[a[i].r] ^ a[i].x){
			printf("%d",i - 1);
			return 0;
		}
		if (f[a[i].l] != f[a[i].r]){
			int t = f[a[i].l];
			f[t] = f[a[i].r];
			rank[t] = rank[a[i].l] ^ rank[a[i].r] ^ a[i].x;
		}
	}
	printf("%d",n);
}
