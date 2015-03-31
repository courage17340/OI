#include <cstdio>
int a[1010][1010],ans,n,m,k,x;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) scanf("%d",&a[i][j]);
	ans = 0;
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) ans ^= a[i][j] * a[j][i];
	scanf("%d",&m);
	while (m--){
		scanf("%d",&k);
		if (k == 3) printf("%d",ans);else{
			scanf("%d",&x);
			ans ^= 1;
		}
	}
	printf("\n");
}
