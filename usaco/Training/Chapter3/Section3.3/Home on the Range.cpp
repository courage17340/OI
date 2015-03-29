/*
USER: courage2
LANG: C++
TASK: range
*/
#include <cstdio>
int a[260][260],n,x,f[260][260];
char s[260];
int main(){
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%s",s);
		for (int j = 1;j <= n;j++) a[i][j] = s[j - 1] - '0';
	}
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) f[i][j] = a[i][j];
	for (int k = 2;k <= n;k++){
		x = 0;
		for (int i = 1;i + k - 1 <= n;i++)
			for (int j = 1;j + k - 1 <= n;j++)
				if (a[i][j] && a[i + k - 1][j + k - 1] && f[i][j + 1] == k - 1 && f[i + 1][j] == k - 1){
					x++;
					f[i][j] = k;
				}
		if (!x) break;
		printf("%d %d\n",k,x);
	}
}
