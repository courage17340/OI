#include<cstdio>
#include<algorithm>
int n,a[100010],ans;
bool f=0;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	ans=0;
	for (int i=0;i<n;i++) if (a[i]==i) ans++;
	for (int i=0;i<n;i++) if (a[i]!=i && a[a[i]]==i) f=1;
	if (f) ans++;
	ans++;
	if (ans>n) ans=n;
	printf("%d",ans);
}
