#include<cstdio>
#include<algorithm>
int a[100010],n,m,x;
char s[10];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%s",s);
	std::sort(a+1,a+n+1);
	scanf("%d",&m);
	while (m--){
		scanf("%d",&x);
		printf("%d\n",a[x]);
	}
}