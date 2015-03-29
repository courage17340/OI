#include<cstdio>
struct node{int k;node *next;};
node *a[110],*p,*q;
int n,m,k,x,ans,f[210]={0},g[110]={0};
bool v[110]={0};
void work(int x){
	ans--;
	v[x] = 1;
	p = a[x];
	while (p->next != 0){
		p = p->next;
		g[p->k]--;
		if (p->k && !v[p->k] && !g[p->k]) work(p->k);
	}
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		a[i] = new node;
		a[i]->next = 0;
		a[i]->k = 0;
	}
	for (int i = 1;i <= n;i++){
		scanf("%d%d",&x,&m);
		f[x] = i;
		p = a[i];
		while (m--){
			scanf("%d",&x);
			q = new node;
			q->next = 0;
			q->k = x;
			p->next = q;
			p = q;
		}
	}
	ans=n;
	for (int i = 1;i <= n;i++){
		p = a[i];
		while (p->next != 0){
			p = p->next;
			p->k = f[p->k];
			g[p->k]++;
		}
	}
	for (int i = 1;i <= n;i++) if (!g[i] && !v[i]) work(i);
	if (ans) printf("%d",ans);else printf("YES");
}
