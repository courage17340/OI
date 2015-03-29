#include <cstdio>
#include <algorithm>
struct rec{int k,x,y,z;};
rec a[50010];
int b[100010],n,m,p,q,k;
char s[3];
struct node{int l,r,x;};
node f[400010];
int find(int x){
	int l = 1,r = n,m;
	while (l != r){
		m = (l + r) >> 1;
		if (x == b[m]) return m;
		if (x < b[m]) r = m - 1;else l = m + 1;
	}
	return l;
}
void build(int k,int l,int r){
	f[k].l = l;
	f[k].r = r;
	f[k].x = 0;
	if (l < r){
		int m = (l + r) >> 1;
		build(k * 2,l,m);
		build(k * 2 + 1,m + 1,r);
	}
}
void add(int k,int l,int r,int d){
	if (f[k].l == l && f[k].r == r){
		f[k].x += d;
		return;
	}
	int m = (f[k].l + f[k].r) >> 1;
	if (r <= m) add(k * 2,l,r,d);
	else if (l > m) add(k * 2 + 1,l,r,d);
	else{
		add(k * 2,l,m,d);
		add(k * 2 + 1,m + 1,r,d);
	}
}
int val(int k,int x){
	if (f[k].l == f[k].r) return f[k].x;
	int m = (f[k].l + f[k].r) >> 1;
	if (x <= m) return val(k * 2,x) + f[k].x;else return val(k * 2 + 1,x) + f[k].x;
}
int main(){
	scanf("%d%d",&n,&m);
	n = 0;
	for (int i = 1;i <= m;i++){
		scanf("%s%d",s,&a[i].x);
		b[++n] = a[i].x;
		a[i].k = (s[0] == 'S');
		if (!a[i].k){
			scanf("%d%d",&a[i].y,&a[i].z);
			b[++n] = a[i].y;
		}
	}
	std::sort(b + 1,b + n + 1);
	p = 1;
	k = 0;
	while (p <= n){
		q = p;
		while (q < n && b[q + 1] == b[p]) q++;
		b[++k] = b[p++];
	}
	n = k;
	for (int i = 1;i <= m;i++){
		a[i].x = find(a[i].x);
		if (!a[i].k) a[i].y = find(a[i].y);
	}
	build(1,1,n);
	for (int i = 1;i <= m;i++)
		if (a[i].k == 0) add(1,a[i].x,a[i].y,a[i].z);
		else printf("%d\n",val(1,a[i].x));
}
