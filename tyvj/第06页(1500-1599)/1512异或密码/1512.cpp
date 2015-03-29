#include <cstdio>
struct rec{int l,r,x;};
rec f[200010];
int a[50010],n,m,k,x,y;
void build(int k,int l,int r){
	f[k].l = l;
	f[k].r = r;
	if (l == r){
		f[k].x = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(k * 2,l,m);
	build(k * 2 + 1,m + 1,r);
	f[k].x = f[k * 2].x ^ f[k * 2 + 1].x;
}
int key(int k,int l,int r){
	if (f[k].l == l && f[k].r == r) return f[k].x;
	int m = (f[k].l + f[k].r) >> 1;
	if (r <= m) return key(k * 2,l,r);
	if (l > m) return key(k * 2 + 1,l,r);
	return key(k * 2,l,m) ^ key(k * 2 + 1,m + 1,r);
}
void change(int x,int y){
	int k = 1,m;
	while (f[k].l != f[k].r){
		m = (f[k].l + f[k].r) >> 1;
		k *= 2;
		if (x > m) k++;
	}
	f[k].x = y;
	while (k > 1){
		k >>= 1;
		f[k].x = f[k * 2].x ^ f[k * 2 + 1].x;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while (m--){
		scanf("%d%d%d",&k,&x,&y);
		if (k == 0) printf("%d\n",key(1,x,y));else change(x,y);
	}
}
