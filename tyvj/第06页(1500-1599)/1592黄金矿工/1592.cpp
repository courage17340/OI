#include <cstdio>
int n,a[310][310] = {{0}},ans,x,k;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++){
		scanf("%d",&x);
		if (x == 0) x = -1e7;
		a[i][j] = a[i - 1][j] + x;
	}
	ans = 0;
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++){
			x = 0;
			for (int k = 1;k <= n;k++){
				x += a[j][k] - a[i - 1][k];
				if (x < 0) x = 0;
				if (ans < x) ans = x;
			}
		}
	ans -= 10;
	if (ans < 0) ans = 0;
	printf("%d",ans);
}
