#include <cstdio>
typedef long long ll;
char s[3];
struct rec{ll s,t;int l,r;};
rec f[400010];
int a[100010],n,q,x,y,z;
void build(int k,int l,int r){
	f[k].l = l;
	f[k].r = r;
	f[k].t = 0;
	if (l == r){
		f[k].s = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(k * 2,l,m);
	build(k * 2 + 1,m + 1,r);
	f[k].s = f[k * 2].s + f[k * 2 + 1].s;
}
void add(int k,int l,int r,int x){
	if (l == f[k].l && r == f[k].r){
		f[k].s += (ll)x * (r - l + 1);
		f[k].t += x;
		return;
	}
	if (f[k].t){
		f[k * 2].s += f[k].t * (f[k * 2].r - f[k * 2].l + 1);
		f[k * 2].t += f[k].t;
		f[k * 2 + 1].s += f[k].t * (f[k * 2 + 1].r - f[k * 2 + 1].l + 1);
		f[k * 2 + 1].t += f[k].t;
		f[k].t = 0;
	}
	int m = (f[k].l + f[k].r) >> 1;
	if (r <= m) add(k * 2,l,r,x);else
	if (l > m) add(k * 2 + 1,l,r,x);else{
		add(k * 2,l,m,x);
		add(k * 2 + 1,m + 1,r,x);
	}
	f[k].s = f[k * 2].s + f[k * 2 + 1].s;
}
ll sum(int k,int l,int r){
	if (f[k].l == l && f[k].r == r) return f[k].s;
	if (f[k].t){
		f[k * 2].s += f[k].t * (f[k * 2].r - f[k * 2].l + 1);
		f[k * 2].t += f[k].t;
		f[k * 2 + 1].s += f[k].t * (f[k * 2 + 1].r - f[k * 2 + 1].l + 1);
		f[k * 2 + 1].t += f[k].t;
		f[k].t = 0;
	}
	int m = (f[k].l + f[k].r) >> 1;
	if (r <= m) return sum(k * 2,l,r);
	if (l > m) return sum(k * 2 + 1,l,r);
	return sum(k * 2,l,m) + sum(k * 2 + 1,m + 1,r);
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while (q--){
		scanf("%s",s);
		if (s[0] == 'C'){
			scanf("%d%d%d",&x,&y,&z);
			add(1,x,y,z);
		}else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",sum(1,x,y));
		}
	}
}