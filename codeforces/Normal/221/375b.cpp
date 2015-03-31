#include <cstdio>
#include <cstring>
#include <algorithm>
char s[5010];
int a[5010][5010] = {{0}},f[5010][5010] = {{0}},n,m,ans = 0,b[5010],p;
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%s",s);
		for (int j = 1;j <= m;j++) a[i][j] = (s[j - 1] == '1');
	}
	for (int i = 1;i <= n;i++)
		for (int j = m;j >= 1;j--) if (a[i][j + 1] == 0) f[i][j] = a[i][j];else f[i][j] = a[i][j] + f[i][j + 1];
	for (int i = 1;i <= m;i++){
		p = 0;
		for (int j = 1;j <= n;j++) if (a[j][i]) b[++p] = f[j][i];
		std::sort(b + 1,b + p + 1);
		for (int k = 1;k <= p;k++) if (ans < b[k] * (p - k + 1)) ans = b[k] * (p - k + 1);
	}
	printf("%d\n",ans);
}
