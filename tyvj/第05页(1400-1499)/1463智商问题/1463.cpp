#include<cstdio>
#include<algorithm>
int a[1000010],n,m,p,x;
struct rec{int x,k,ans;};
rec b[1000010];
bool cmp1(rec a,rec b){
	return (a.x<b.x);
}
bool cmp2(rec a,rec b){
	return (a.k<b.k);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	m=0;
	while (scanf("%d",&x)!=EOF){
		m++;
		b[m].k=m;
		b[m].x=x;
	}
	std::sort(a+1,a+n+1);
	std::sort(b+1,b+m+1,cmp1);
	p=0;
	for (int q=1;q<=m;q++){
		while (p<n && a[p+1]<b[q].x) p++;
		b[q].ans=p+1;
	}
	std::sort(b+1,b+m+1,cmp2);
	for (int i=1;i<=m;i++) printf("%d\n",b[i].ans);
}
