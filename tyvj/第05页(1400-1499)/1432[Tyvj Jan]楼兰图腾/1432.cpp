#include <cstdio>
struct node{int l,r,s;};
typedef long long ll;
node f[800010];
int a[200010],b[200010],c[200010],n,m,l,r;
ll a1,a2;
void build(int k,int l,int r){
	f[k].l = l;
	f[k].r = r;
	f[k].s = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(k * 2,l,m);
	build(k * 2 + 1,m + 1,r);
}

int sum(int k,int l,int r){
	if (l > r) return 0;
	if (l == f[k].l && r == f[k].r) return f[k].s;
	int m = (f[k].l + f[k].r) >> 1;
	if (r <= m) return sum(k * 2,l,r);
	if (l > m) return sum(k * 2 + 1,l,r);
	return sum(k * 2,l,m) + sum(k * 2 + 1,m + 1,r);
}

void add(int x){
	int k = 1,m;
	while (f[k].l != f[k].r){
		m = (f[k].l + f[k].r) >> 1;
		if (x <= m) k = k * 2;else k = k * 2 + 1;
	}
	f[k].s = 1;
	while (k > 1){
		k >>= 1;
		f[k].s = f[k * 2].s + f[k * 2 + 1].s;
	}
}

int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	for (int i = 1;i <= n;i++){
		b[i] = sum(1,1,a[i] - 1);
		add(a[i]);
	}
	build(1,1,n);
	for (int i = n;i >= 1;i--){
		c[i] = sum(1,1,a[i] - 1);
		add(a[i]);
	}
	a1 = a2 = 0;
	for (int i = 2;i < n;i++) a1 += (i - b[i] - 1) * (n - i - c[i]);
	for (int i = 2;i < n;i++) a2 += b[i] * c[i];
	printf("%lld %lld\n",a1,a2);
}
