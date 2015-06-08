#include <cstdio>
#include <algorithm>
int n,m,a[110][110],f[4],ans = 0;
char s[100];
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;++i){
		scanf("%s",s);
		for (int j = 1;j <= m;++j) a[i][j] = s[j - 1];	
	}
	for (int i = 1;i < n;++i)
		for (int j = 1;j < m;++j){
			f[0] = a[i][j];
			f[1] = a[i][j + 1];
			f[2] = a[i + 1][j];
			f[3] = a[i + 1][j + 1];
			std::sort(f,f + 4);
			if (f[0] == 'a' && f[1] == 'c' && f[2] == 'e' && f[3] == 'f') ans++;
		}
	printf("%d\n",ans);
}
