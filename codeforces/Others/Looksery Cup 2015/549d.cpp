#include <cstdio>
int n,m,a[200][200],ans,t;
char s[200];
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;++i){
		scanf("%s",s);
		for (int j = 1;j <= m;++j) a[i][j] = s[j - 1] == 'W' ? 1 : -1;
	}
	ans = 0;
	for (int i = n;i >= 1;--i)
		for (int j = m;j >= 1;--j) if (a[i][j]){
			t = a[i][j];
			ans++;
			for (int p = 1;p <= i;++p)
				for (int q = 1;q <= j;++q) a[p][q] -= t;
		}
	printf("%d\n",ans);
}
