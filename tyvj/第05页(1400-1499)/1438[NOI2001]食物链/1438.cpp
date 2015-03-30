#include <cstdio>
int f[50010],rank[50010] = {0},n,m,k,x,y,ans,t;
int father(int x){
	if (f[x] == x) return x;
	int y = father(f[x]);
	rank[x] = (rank[x] + rank[f[x]]) % 3;
	return f[x] = y;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) f[i] = i;
	ans = 0;
	for (int i = 1;i <= m;i++){
		scanf("%d%d%d",&k,&x,&y);
		if (x > n || y > n){
			ans++;
			continue;
		}
		if (k == 1){
			if (father(x) == father(y)){
				if (rank[x] != rank[y]) ans++;
				continue;
			}
			t = father(x);
			f[t] = father(y);
			rank[t] = (rank[x] * 2 + rank[y]) % 3;
		}
		if (k == 2){
			if (father(x) == father(y)){
				if (rank[x] - rank[y] != 1 && rank[x] - rank[y] != -2) ans++;
				continue;
			}
			t = father(x);
			f[t] = father(y);
			rank[t] = (rank[x] * 2 + rank[y] + 1) % 3;
		}
	}
	printf("%d\n",ans);
}
