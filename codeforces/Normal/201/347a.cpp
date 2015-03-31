#include<cstdio>
#include<algorithm>
int n,a[110],t;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n;i++) if (a[1]<a[i]){
		t=a[1];
		a[1]=a[i];
		a[i]=t;
	}
	for (int i=2;i<n;i++) if (a[i]<a[n]){
		t=a[i];
		a[i]=a[n];
		a[n]=t;
	}
	std::sort(a+2,a+n);
	for (int i=1;i<n;i++) printf("%d ",a[i]);
	printf("%d\n",a[n]);
}
