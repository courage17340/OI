#include <cstdio>
struct rec{int x;rec *pre;};
rec *a[400010],*p;
int n,m,k,b[400010],c[4000010],f[400010],x,y,ans;
bool v[400010] = {0},u[400010] = {0};
int father(int x){
	if (f[x] == x) return x;
	f[x] = father(f[x]);
	return f[x];
}
void del(rec * x){
	if (x->pre != NULL) del(x->pre);
	delete x;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n;i++){
		a[i] = new rec;
		a[i]->x = -1;
		a[i]->pre = NULL;
	}
	while (m--){
		scanf("%d%d",&x,&y);
		p = new rec;
		p->x = y;
		p->pre = a[x];
		a[x] = p;
		p = new rec;
		p->x = x;
		p->pre = a[y];
		a[y] = p;
	}
	scanf("%d",&k);
	for (int i = 1;i <= k;i++){
		scanf("%d",&b[i]);
		v[b[i]] = 1;
	}
	for (int i = 0;i < n;i++) f[i] = i;
	for (int i = 0;i < n;i++) if (!v[i]){
		p = a[i];
		while (p->x != -1){
			if (!v[p->x] && father(p->x) != father(i)) f[father(p->x)] = father(i);
			p = p->pre;
		}
	}
	for (int i = 0;i < n;i++) u[father(i)] = 1;
	ans = 0;
	for (int i = 0;i < n;i++) ans += u[i];
	c[k] = ans;
	for (int i = k;i >= 1;i--){
		v[b[i]] = 0;
		p = a[b[i]];
		while (p->x != -1){
			if (!v[p->x] && father(p->x) != father(b[i])){
				f[father(p->x)] = father(b[i]);
				ans--;
			}
			p = p->pre;
		}
		c[i - 1] = ans;
	}
	for (int i = 0;i <= k;i++) printf("%d\n",c[i] - i);
	for (int i = 0;i < n;i++) del(a[i]);
}
