#include<cstdio>
#include<algorithm>
int a[2010],ans,n,x,y;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) if (a[i]<0) a[i]=-a[i];
	a[1]=-a[1];
	for (int i=2;i<n;i++) if (a[i]){
		x=y=0;
		for (int j=1;j<=n;j++) if (a[i]>a[j] && i<j || a[i]<a[j] && i>j) x++;
		for (int j=1;j<=n;j++) if (-a[i]>a[j] && i<j || -a[i]<a[j] && i>j) y++;
		if (x>y) a[i]=-a[i];
	}
	ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) if (a[i]>a[j]) ans++;
	printf("%d",ans);
}
