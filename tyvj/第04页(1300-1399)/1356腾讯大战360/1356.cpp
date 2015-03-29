#include <cstdio>
#include <cstring>
int n,m,p,q,x,y,z,ans,r = 0,d[5010],e[5010],b[5010];
struct node{int x,c;node * next;};
node *a[5010],pool[10010],*t;
bool v[5010] = {0};
inline node *get(){
	return &pool[++r];
}
inline int next(int x){
	x++;
	if (x == 5010) x = 0;
	return x;
}
inline int min(int a,int b){
	return a < b ? a : b;
}
inline int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) a[i] = 0;
	while (m--){
		scanf("%d%d%d",&x,&y,&z);
		t = get();
		t->x = y;
		t->c = z;
		t->next = a[x];
		a[x] = t;
		t = get();
		t->x = x;
		t->c = z;
		t->next = a[y];
		a[y] = t;
	}
	scanf("%d%d",&x,&y);
	for (int i = 1;i <= n;i++) if (i != x) d[i] = 1e9;else d[i] = 0;
	v[x] = 1;
	p = q = 0;
	b[0] = x;
	while (p != next(q)){
		t = a[b[p]];
		while (t != 0){
			if (d[t->x] > d[b[p]] + t->c){
				d[t->x] = d[b[p]] + t->c;
				if (!v[t->x]){
					q = next(q);
					b[q] = t->x;
					v[t->x] = 1;
				}
			}
			t = t->next;
		}
		v[b[p]] = 0;
		p = next(p);
	}
	memset(v,0,sizeof v);
	for (int i = 1;i <= n;i++) if (i != y) e[i] = 1e9;else e[i] = 0;
	v[y] = 1;
	p = q = 0;
	b[0] = y;
	while (p != next(q)){
		t = a[b[p]];
		while (t != 0){
			if (e[t->x] > e[b[p]] + t->c){
				e[t->x] = e[b[p]] + t->c;
				if (!v[t->x]){
					q = next(q);
					b[q] = t->x;
					v[t->x] = 1;
				}
			}
			t = t->next;
		}
		v[b[p]] = 0;
		p = next(p);
	}
	ans = d[y];
	for (int i = 1;i <= n;i++) ans = min(ans,max(d[i],e[i]));
	if (ans < 1e9) printf("%d",ans);else printf("Peace!");
}
