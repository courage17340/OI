#include <cstdio>
struct rec{int l,r,s;};
rec f[400010];
int k,x,y,n,m;
void build(int k,int l,int r){
	f[k].l = l;
	f[k].r = r;
	f[k].s = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(k * 2,l,m);
	build(k * 2 + 1,m + 1,r);
}
int val(int x){
	int ans = 0,k = 1,m;
	while (f[k].l != f[k].r){
		ans += f[k].s;
		m = (f[k].l + f[k].r) >> 1;
		if (x <= m) k = k * 2;else k = k * 2 + 1;
	}
	ans += f[k].s;
	return ans & 1;
}
void add(int k,int l,int r){
	if (l == f[k].l && r == f[k].r){
		f[k].s++;
		return;
	}
	int m = (f[k].l + f[k].r) >> 1;
	if (r <= m) add(k * 2,l,r);else
		if (l > m) add(k * 2 + 1,l,r);else{
			add(k * 2,l,m);
			add(k * 2 + 1,m + 1,r);
		}
}
int main(){
	scanf("%d",&n);
	build(1,1,n);
	scanf("%d",&m);
	while (m--){
		scanf("%d",&k);
		if (k == 1){
			scanf("%d%d",&x,&y);
			add(1,x,y);
		}else{
			scanf("%d",&x);
			printf("%d\n",val(x));
		}
	}
}
