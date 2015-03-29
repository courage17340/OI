#include <cstdio>
int f[5010],n,ans,p,k;
int main(){
	scanf("%d",&n);
	f[1] = 1;
	f[2] = f[3] = 2;
	p = 3;
	for (int i = 3;i <= n;i++){
		k = f[i];
		while (k-- && p < n) f[++p] = i;
	}
	ans = 0;
	for (int i = 1;i <= n;i++) ans += f[i];
	printf("%d",ans);
}
