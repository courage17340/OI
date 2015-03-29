#include<cstdio>
#include<algorithm>
struct rec{int x,y;};
rec a[1010],b[1010];
int n,m,ans,x,y,c[1010],p,q,k;
bool flag;
bool cmp(rec a,rec b){
	return a.x<b.x;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		b[i].x=a[i].x+a[i].y;
		b[i].y=i;
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		c[i]=x+y;
	}
	std::sort(b+1,b+n+1,cmp);
	ans=k=0;
	p=1;
	while (p<=n){
		q=p;
		while (q<n && b[q+1].x==b[p].x) q++;
		if (ans<q-p+1){
			flag=1;
			for (int j=1;j<=m;j++) if (b[p].x==c[j]){
				flag=0;
				break;
			}
			if (flag){
				ans=q-p+1;
				k=p;
			}
		}
		p=q+1;
	}
	printf("%d %d",a[b[k].y].x,a[b[k].y].y);
}
