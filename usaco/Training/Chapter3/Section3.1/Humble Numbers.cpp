/*
ID: courage2
TASK: humble
LANG: C++
*/
#include <cstdio>
int a[110],b[100010],f[110] = {0},n,m,x,k;
int main(){
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	b[0] = 1;
	for (int i = 1;i <= m;i++){
		x = 0;
		for (int j = 1;j <= n;j++){
			while (a[j] * b[f[j]] <= b[i - 1]) f[j]++;
			if (!x || x > a[j] * b[f[j]]) x = a[j] * b[f[j]];
		}
		b[i] = x;
	}
	printf("%d\n",b[m]);
}
