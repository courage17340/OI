/*
USER: courage2
LANG: C++
TASK: butter
*/
#include <cstdio>
#include <cstring>
struct node{
	int x,c;
	node *next;
};
node *a[810],*t,pool[3010];
int k,n,m,b[100010],c[810],d[810],x,y,z,ans = 2e9;
bool v[810];
node *get(){
	static int x = 0;
	return &pool[x++];
}
int spfa(int x){
	memset(d,1,sizeof d);
	memset(v,0,sizeof v);
	d[x] = 0;
	int p,q;
	p = q = 1;
	b[1] = x;
	v[x] = 1;
	while (p <= q){
		t = a[b[p]];
		while (t != NULL){
			if (d[t->x] > d[b[p]] + t->c){
				d[t->x] = d[b[p]] + t->c;
				if (!v[t->x]){
					v[t->x] = 1;
					b[++q] = t->x;
				}
			}
			t = t->next;
		}
		v[b[p++]] = 0;
	}
	int y = 0;
	for (int i = 1;i <= k;i++) y += d[c[i]];
	return y;
}
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	scanf("%d%d%d",&k,&n,&m);
	for (int i = 1;i <= n;i++) a[i] = NULL;
	for (int i = 1;i <= k;i++) scanf("%d",c + i);
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
	for (int i = 1;i <= n;i++) ans = min(ans,spfa(i));
	printf("%d\n",ans);
}
