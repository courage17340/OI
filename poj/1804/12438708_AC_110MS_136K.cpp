#include <cstdio>
int t,n,a[1010],ans;
int main(){
	scanf("%d",&t);
	for (int te = 1;te <= t;te++){
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
		ans = 0;
		for (int i = 1;i < n;i++)
			for (int j = i + 1;j <= n;j++) if (a[i] > a[j]) ans++;
		printf("Scenario #%d:\n%d\n",te,ans);
		if (te < t) printf("\n");
	}
}	