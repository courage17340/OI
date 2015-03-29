#include<cstdio>
int a[100010],b[100010],n;
bool f(){
	for (int i=1;i<=n;i++) if (a[i]!=b[i]) return 0;
	return 1;
}
int main(){
	while (1){
		scanf("%d",&n);
		if (n==0) break;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) b[a[i]]=i;
		if (f()) printf("ambiguous\n");else printf("not ambiguous\n");
	}
}