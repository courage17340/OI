#include <cstdio>
int n,a[1010],f[1010],ans;
int main(){
	while (scanf("%d",&n) != EOF){
		for (int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			f[i] = 0;
		}
		a[0] = f[0] = 0;
		for (int i = 1;i <= n;i++) for (int j = 0;j < i;j++)
			if (a[i] > a[j] && a[i] - a[j] <= i - j && f[i] < f[j] + 1 && (j == 0 || f[j])) f[i] = f[j] + 1;
		ans = 0;
		for (int i = 1;i <= n;i++) if (ans < f[i]) ans = f[i];
		printf("%d\n",ans);
	}
}
