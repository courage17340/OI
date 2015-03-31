#include <cstdio>
#include <algorithm>
int n,a[500010],k,ans;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	a[n + 1] = 1e9;
	std::sort(a + 1,a + n + 1);
	ans = n / 2;
	k = 0;
	while (1){
		k++;
		if (k * 2 > n){
			ans = k - 1;
			break;
		}
		while (a[n - ans + k] < a[k] * 2) ans--;
		if (k > ans){
			ans = k - 1;
			break;
		}
		if (k == ans) break;
	}
	printf("%d",n - ans);
}
