/*
USER: courage2
LANG: C++
TASK: theme
*/
#include <cstdio>
int a[5010],n,ans,p,q;
int main(){
	freopen("theme.in","r",stdin);
	freopen("theme.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	ans = 1;
	for (int i = 1;i < n;i++)
		for (int j = i + ans;j + ans <= n;j++){
			p = i;
			q = j;
			while (p + 1 < j && q < n && a[p + 1] - a[q + 1] == a[i] - a[j]){
				p++;
				q++;
			}
			if (p - i + 1 > ans) ans = p - i + 1;
		}
	if (ans < 5) ans = 0;
	printf("%d\n",ans);
}
