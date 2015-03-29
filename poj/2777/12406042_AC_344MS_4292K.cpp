#include <cstdio>
char s[3];
struct rec{int l,r,sta,flag;};
rec a[400010];
int n,t,m,x,y,z;
void swap(int & a,int & b){
	int t = a;
	a = b;
	b = t;
}
void build(int k,int l,int r){
	a[k].l = l;
	a[k].r = r;
	a[k].sta = 1;
	a[k].flag = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(k * 2,l,m);
	build(k * 2 + 1,m + 1,r);
}
int count(int x){
	int y = 0;
	while (x){
		y += (x & 1);
		x >>= 1;
	}
	return y;
}
void paint(int k,int l,int r,int c){
	if (l == a[k].l && r == a[k].r){
		a[k].flag = a[k].sta = (1 << (c - 1));
		return;
	}
	if (a[k].flag){
		a[k].sta = a[k * 2].sta = a[k * 2].flag = a[k * 2 + 1].sta = a[k * 2 + 1].flag = a[k].flag;
		a[k].flag = 0;
	}
	int m = (a[k].l + a[k].r) >> 1;
	if (r <= m) paint(k * 2,l,r,c);else
	if (l > m) paint(k * 2 + 1,l,r,c);else{
		paint(k * 2,l,m,c);
		paint(k * 2 + 1,m + 1,r,c);
	}
	a[k].sta = a[k * 2].sta | a[k * 2 + 1].sta;
}
int work(int k,int l,int r){
	if (a[k].l == l && a[k].r == r) return a[k].sta;
	if (a[k].flag){
		a[k].sta = a[k * 2].sta = a[k * 2].flag = a[k * 2 + 1].sta = a[k * 2 + 1].flag = a[k].flag;
		a[k].flag = 0;
	}
	int m = (a[k].l + a[k].r) >> 1;
	int y;
	if (r <= m) return work(k * 2,l,r);else
	if (l > m) return work(k * 2 + 1,l,r);else
	return work(k * 2,l,m) | work(k * 2 + 1,m + 1,r);
}
int main(){
	scanf("%d%d%d",&n,&t,&m);
	build(1,1,n);
	while (m--){
		scanf("%s",s);
		if (s[0] == 'C'){
			scanf("%d%d%d",&x,&y,&z);
			if (x > y) swap(x,y);
			paint(1,x,y,z);
		}else{
			scanf("%d%d",&x,&y);
			if (x > y) swap(x,y);
			printf("%d\n",count(work(1,x,y)));
		}
	}
}