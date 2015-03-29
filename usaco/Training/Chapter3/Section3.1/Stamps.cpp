/*
USER: courage2
LANG: C++
TASK: stamps
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
int min(int a,int b){
	return a < b ? a : b;
}
int n,m,a[51],f[2000010],mx;
int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	std::sort(a + 1,a + n + 1);
	memset(f,1,sizeof f);
	f[0] = 0;
	mx = m * a[n] + 1;
	for (int i = 1;i <= mx;i++)
		for (int j = 1;j <= n;j++) if (i >= a[j]) f[i] = min(f[i],f[i - a[j]] + 1);
	for (int i = 1;i <= mx;i++) if (f[i] > m){
		printf("%d\n",i - 1);
		return 0;
	}
}
