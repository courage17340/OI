#include <cstdio>
#include <cstring>
int n,m,p,q,x,y,z,ans,r = 0,d[10010],b[10010];
struct node{int x,c;node * next;};
node *a[10010],pool[50010],*t;
bool v[10010] = {0};
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
	}
	d[1] = 0;
	for (int i = 2;i <= n;i++) d[i] = 1e9;
	v[1] = 1;
	p = q = 0;
	b[0] = 1;
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
	printf("%d",d[n]);
}
