#include <cstdio>
#include <cstring>
int f[2010],rank[2010],n,m,t,x,y;
bool k;
int father(int x){
	if (x == f[x]) return x;
	int y = f[x];
	f[x] = father(f[x]);
	rank[x] ^= rank[y];
	return f[x];
}
int main(){
	scanf("%d",&t);
	for (int T = 1;T <= t;T++){
		scanf("%d%d",&n,&m);
		memset(rank,0,sizeof rank);
		for (int i = 1;i <= n;i++) f[i] = i;
		k = 1;
		while (m--){
			scanf("%d%d",&x,&y);
			if (!k) continue;
			if (father(x) == father(y)) if (rank[x] == rank[y]) k = 0;
			if (father(x) != father(y)){
				rank[f[x]] = rank[x] ^ rank[y] ^ 1;
				f[f[x]] = f[y];
			}
		}
		if (!k) printf("Scenario #%d:\nSuspicious bugs found!\n\n",T);else printf("Scenario #%d:\nNo suspicious bugs found!\n\n",T);
	}
}