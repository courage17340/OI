/*
USER: courage2
LANG:C++
TASK: stall4
*/
#include <cstdio>
#include <cstring>
int n,m,k,x,ans,link[210];
bool a[210][210] = {{0}},v[210] = {0};
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
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%d",&k);
		for (int j = 1;j <= k;j++){
			scanf("%d",&x);
			a[i][x] = 1;
		}
	}
	ans = 0;
	for (int i = 1;i <= n;i++){
		memset(v,0,sizeof v);
		if (find(i)) ans++;
	}
	printf("%d\n",ans);
}
