#include<cstdio>
#include<algorithm>
struct rec{int x,y,d;};
rec a[10010];
int n,p,q,x,y,f[110],ans=0;
bool cmp(rec a,rec b){
	return (a.d<b.d);
}
int father(int x){
	if (x==f[x]) return x;
	f[x]=father(f[x]);
	return f[x];
}
int main(){
	scanf("%d",&n);
	p=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			scanf("%d",&x);
			if (x){
				p++;
				a[p].x=i;
				a[p].y=j;
				a[p].d=x;
			}
		}
	std::sort(a+1,a+p+1,cmp);
	scanf("%d",&q);
	for (int i=1;i<=n;i++) f[i]=i;
	while (q--){
		scanf("%d%d",&x,&y);
		if (father(x)!=father(y)) f[father(x)]=father(y);
	}
	for (int i=1;i<=p;i++)
		if (father(a[i].x)!=father(a[i].y)){
			ans+=a[i].d;
			f[father(a[i].x)]=father(a[i].y);
		}
	printf("%d",ans);
}