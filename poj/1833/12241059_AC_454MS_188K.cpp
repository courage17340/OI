#include<cstdio>
int a[1030],t,k,p,q,n;
inline void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		while (k--){
			p=n;
			while (p>1 && a[p]<a[p-1]) p--;
			if (p==1 && a[1]==n){
				for (int i=1;i<=n;i++) a[i]=i;
				continue;
			}
			p--;
			q=n;
			while (a[q]<a[p]) q--;
			swap(a[p],a[q]);
			p++;
			q=n;
			while (p<q){
				swap(a[p],a[q]);
				p++;
				q--;
			}
		}
		for (int i=1;i<n;i++) printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
}