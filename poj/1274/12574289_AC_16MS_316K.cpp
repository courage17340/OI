#include <cstdio>
#include <cstring>
int n,m,link[210],a[210][210],k[210],ans;
bool v[210];
bool find(int x){
	for (int i = 1;i <= k[x];i++) if (!v[a[x][i]]){
		v[a[x][i]] = 1;
		if (link[a[x][i]] == 0 || find(link[a[x][i]])){
			link[a[x][i]] = x;
			return 1;
		}
	}
	return 0;
}
int main(){
	while (scanf("%d%d",&n,&m) != EOF){
		memset(link,0,sizeof link);
		memset(k,0,sizeof k);
		for (int i = 1;i <= n;i++){
			scanf("%d",&k[i]);
			for (int j = 1;j <= k[i];j++) scanf("%d",&a[i][j]);
		}
		ans = 0;
		for (int i = 1;i <= n;i++){
			memset(v,0,sizeof v);
			if (find(i)) ans++;
		}
		printf("%d\n",ans);
	}
}