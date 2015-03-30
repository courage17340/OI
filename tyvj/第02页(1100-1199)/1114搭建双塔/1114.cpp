#include <cstdio>
bool f[2010][2010] = {{0}};
int n,a[110],tot = 0;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	f[0][0] = 1;
	for (int k = 1;k <= n;k++){
		tot += a[k];
		for (int i = tot;i >= 0;i--)
			for (int j = tot;j >= 0;j--){
				if (i < a[k] && j < a[k]) break;
				if (i >= a[k]) f[i][j] |= f[i - a[k]][j];
				if (j >= a[k]) f[i][j] |= f[i][j - a[k]];
			}
	}
	for (int i = tot;i > 0;i--) if (f[i][i]){
		printf("%d\n",i);
		return 0;
	}
	printf("Impossible\n");
}
