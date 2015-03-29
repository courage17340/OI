#include<cstdio>
typedef long long ll;
struct rec{int l,r,u,d,s,t;};
rec f[1100010];
int n,m,l,r,u,d,k,x,y;
inline int min(int a,int b){
	return (a<b?a:b);
}
inline int max(int a,int b){
	return (a>b?a:b);
}
void build(int k,int l,int r,int u,int d){
	f[k].l=l;
	f[k].r=r;
	f[k].u=u;
	f[k].d=d;
	f[k].t=f[k].s=0;
	if (l==r && u==d) return;
	int m=(l+r)>>1,n=(u+d)>>1;
	build(4*k-2,l,m,u,n);
	if (l!=r) build(4*k-1,m+1,r,u,n);
	if (u!=d) build(4*k,l,m,n+1,d);
	if (l!=r && u!=d) build(4*k+1,m+1,r,n+1,d);
}
void add(int k,int l,int r,int u,int d,int x){
	if (l==f[k].l && r==f[k].r && u==f[k].u && d==f[k].d){
		f[k].s+=(r-l+1)*(d-u+1)*x;
		f[k].t+=x;
		return;
	}
	if (f[k].t){
		for (int i=4*k-2;i<=4*k+1;i++)
			if (f[i].l){
				f[i].s+=(f[i].r-f[i].l+1)*(f[i].d-f[i].u+1)*f[k].t;
				f[i].t+=f[k].t;
			}
		f[k].t=0;
	}
	int m=(f[k].l+f[k].r)>>1,n=(f[k].u+f[k].d)>>1;
	if (l<=m && u<=n) add(4*k-2,l,min(m,r),u,min(n,d),x);
	if (m<r && u<=n) add(4*k-1,max(m+1,l),r,u,min(n,d),x);
	if (l<=m && n<d) add(4*k,l,min(m,r),max(n+1,u),d,x);
	if (m<r && n<d) add(4*k+1,max(m+1,l),r,max(n+1,u),d,x);
	f[k].s=f[4*k-2].s+f[4*k-1].s+f[4*k].s+f[4*k+1].s;
}
int sum(int k,int l,int r,int u,int d){
	if (f[k].l==l && f[k].r==r && f[k].u==u && f[k].d==d) return f[k].s;
	if (f[k].t){
		for (int i=4*k-2;i<=4*k+1;i++)
			if (f[i].l){
				f[i].s+=(f[i].r-f[i].l+1)*(f[i].d-f[i].u+1)*f[k].t;
				f[i].t+=f[k].t;
			}
		f[k].t=0;
	}
	int m=(f[k].l+f[k].r)>>1,n=(f[k].u+f[k].d)>>1,x=0;
	if (l<=m && u<=n) x+=sum(4*k-2,l,min(m,r),u,min(n,d));
	if (m<r && u<=n) x+=sum(4*k-1,max(m+1,l),r,u,min(n,d));
	if (l<=m && n<d) x+=sum(4*k,l,min(m,r),max(n+1,u),d);
	if (m<r && n<d) x+=sum(4*k+1,max(m+1,l),r,max(n+1,u),d);
	return x;
}
int main(){
	scanf("%d%d",&n,&m);
	n=m;
	build(1,1,n,1,n);
	while (scanf("%d",&y)!=EOF)
		if (y==1){
			scanf("%d%d%d",&l,&u,&x);
			add(1,l+1,l+1,u+1,u+1,x);
		}else if (y==2){
			scanf("%d%d%d%d",&l,&u,&r,&d);
			printf("%d\n",sum(1,l+1,r+1,u+1,d+1));
		}else break;
}