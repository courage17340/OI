#include <cstdio>
#include <cstring>
int n,m,x,y,ans,link[210];
bool a[210][210] = {{0}},v[210];
bool find(int x){
	for (int i = 1;i <= n;i++) if (a[x][i] && !v[i]){
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
	for (int i = 1;i <= m;i++){
		scanf("%d%d",&x,&y);
		a[x][y] = 1;
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++) if (i != j)
				if (a[i][k] && a[k][j]) a[i][j] = 1;
	ans = 0;
	for (int i = 1;i <= n;i++){
		memset(v,0,sizeof v);
		if (find(i)) ans++;
	}
	printf("%d\n",n - ans);
}
