#include<cstdio>
int n,a[100010],b[100010],p;
int find(int x){
	int l=1,r=p,m;
	while (l!=r){
		m=(l+r)>>1;
		if (b[m]>=x) r=m;else l=m+1;
	}
	return l;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	p=1;
	b[p]=a[1];
	for (int i=2;i<=n;i++){
		if (a[i]>b[p]){
			p++;
			b[p]=a[i];
			continue;
		}
		b[find(a[i])]=a[i];
	}
	printf("%d",p);
}
