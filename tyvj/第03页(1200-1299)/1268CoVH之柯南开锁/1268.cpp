#include <cstdio>
#include <cstring>
int n,m,ans,k,link[110];
bool a[110][110] = {{0}},v[110] = {0};
char s[110];
bool find(int x){
	for (int i = 1;i <= m;i++) if (a[x][i] && !v[i]){
		v[i] = 1;
		if (link[i] == 0 || find(link[i])){
			link[i] = x;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%s",s);
		for (int j = 0;j < m;j++) if (s[j] == '1') a[i][j + 1] = 1;
	}
	ans = 0;
	for (int i = 1;i <= n;i++){
		memset(v,0,sizeof v);
		if (find(i)) ans++;
	}
	printf("%d\n",ans);
}
