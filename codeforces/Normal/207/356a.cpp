#include<cstdio>
int n,m,l,r,x,f[300010]={0};
struct rec{int x;rec *l,*r;};
typedef rec* tree;
tree a[300010],head,tail,p,q;
int main(){
	scanf("%d%d",&n,&m);
	head=new rec;
	head->l=0;
	head->r=0;
	head->x=0;
	p=head;
	for (int i=1;i<=n;i++){
		q=new rec;
		q->r=0;
		p->r=q;
		q->l=p;
		p=q;
		a[i]=p;
		p->x=i;
	}
	tail=new rec;
	tail->l=p;
	p->r=tail;
	while (m--){
		scanf("%d%d%d",&l,&r,&x);
		p=a[x];
		while (p->l!=head && p->l->x>=l){
			p=p->l;
			f[p->x]=x;
			p->l->r=p->r;
			p->r->l=p->l;
		}
		p=a[x];
		while (p->r!=tail && p->r->x<=r){
			p=p->r;
			f[p->x]=x;
			p->l->r=p->r;
			p->r->l=p->l;
		}
	}
	for (int i=1;i<n;i++) printf("%d ",f[i]);
	printf("%d\n",f[n]);
}
