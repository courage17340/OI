#include <cstdio>
struct node{int l,r,s;};
node f[800010];
int a[200010],n,m,l,r;
void build(int k,int l,int r){
	f[k].l = l;
	f[k].r = r;
	if (l == r){
		f[k].s = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(k * 2,l,m);
	build(k * 2 + 1,m + 1,r);
	f[k].s = f[k * 2].s + f[k * 2 + 1].s;
}

int sum(int k,int l,int r){
	if (l == f[k].l && r == f[k].r) return f[k].s;
	int m = (f[k].l + f[k].r) >> 1;
	if (r <= m) return sum(k * 2,l,r);
	if (l > m) return sum(k * 2 + 1,l,r);
	return sum(k * 2,l,m) + sum(k * 2 + 1,m + 1,r);
}

void del(int x){
	int k = 1,m;
	while (f[k].l != f[k].r){
		m = (f[k].l + f[k].r) >> 1;
		if (x <= m) k = k * 2;else k = k * 2 + 1;
	}
	f[k].s = 0;
	while (k > 1){
		k >>= 1;
		f[k].s = f[k * 2].s + f[k * 2 + 1].s;
	}
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	while (m--){
		scanf("%d%d",&l,&r);
		printf("%.2f\n",sum(1,l,r) * 3.14);
		del((l + r) >> 1);
	}
}
