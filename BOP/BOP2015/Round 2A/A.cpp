#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int t,n,q,k,x,y,f[100010],c[100010],ans[100010];
bool v[100010];
vector<int> e[100010];
void search(int x){
	vector<int> t;
	t.clear();
	int n = e[x].size();
	for (int i = 0;i < n;++i) if (!v[e[x][i]]){
		v[e[x][i]] = 1;
		t.push_back(e[x][i]);
		search(e[x][i]);
		f[e[x][i]] = x;
	}
	e[x] = t;
}
void work(int x){
	int n = e[x].size();
	int tmp = 1;
	for (int i = 0;i < n;++i){
		tmp += ans[e[x][i]];
		if (c[x] == c[e[x][i]]) --tmp;
	}
	ans[x] = tmp;
	if (f[x]) work(f[x]);
}
int main(){
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%d",&n);
		for (int i = 1;i <= n;++i) e[i].clear();
		for (int i = 1;i < n;++i){
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		memset(v,0,sizeof v);
		memset(f,0,sizeof f);
		memset(c,0,sizeof c);
		for (int i = 1;i <= n;++i) ans[i] = 1;
		int root = (n + 1) / 2;//rand..
		v[root] = 1;
		search(root);
		printf("Case #%d:\n",T);
		scanf("%d",&q);
		while (q--){
			scanf("%d",&k);
			if (k == 1){
				printf("%d\n",ans[root]);
			}else{
				scanf("%d%d",&x,&y);
				c[x] = y;
				work(x);
			}
		}
	}
}
