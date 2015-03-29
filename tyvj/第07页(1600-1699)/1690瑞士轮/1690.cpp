#include<cstdio>
#include<algorithm>
int n,k,q;
struct rec{int s,v,n;};
rec a[2][200010];
void merge(){ 
	int m=n>>1;
	int p=1,q=m+1,k=0;
	while (p<=m && q<=n)
		if (a[1][p].s>a[1][q].s || (a[1][p].s==a[1][q].s && a[1][p].n<a[1][q].n)) a[0][++k]=a[1][p++];else a[0][++k]=a[1][q++];
	if (p>m) for (int i=k+1;i<=n;i++) a[0][i]=a[1][q+i-k-1];
		else for (int i=k+1;i<=n;i++) a[0][i]=a[1][p+i-k-1];
}
bool cmp(rec a,rec b){
	if (a.s!=b.s) return a.s>b.s;
	return a.n<b.n;
}
int main(){
	scanf("%d%d%d",&n,&k,&q);
	n<<=1;
	for (int i=1;i<=n;i++){
		a[0][i].n=i;
		scanf("%d",&a[0][i].s);
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[0][i].v);
	std::sort(a[0]+1,a[0]+n+1,cmp);
	while (k--){
		for (int i=1;i<=n;i+=2) if (a[0][i].v>a[0][i+1].v){
			a[0][i].s++;
			a[1][(i+1)>>1]=a[0][i];
			a[1][((i+1)>>1)+(n>>1)]=a[0][i+1];
		}else{
			a[0][i+1].s++;
			a[1][(i+1)>>1]=a[0][i+1];
			a[1][((i+1)>>1)+(n>>1)]=a[0][i];
		}
		merge();
	}
	printf("%d\n",a[0][q].n);
}
