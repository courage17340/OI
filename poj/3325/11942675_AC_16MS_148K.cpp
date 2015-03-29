#include<cstdio>
#include<algorithm>
int n,a[1010],ans;
int main(){
	while(1){
		scanf("%d",&n);
		if (n==0) break;
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		std::sort(a,a+n);
		ans=0;
		for (int i=1;i<n-1;i++) ans+=a[i];
		ans/=(n-2);
		printf("%d\n",ans);
	}
}