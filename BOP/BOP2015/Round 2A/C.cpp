#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int t,n,a[1010],f[1010],ans,b[1010][2];
bool v[1010],vf[1010],vb[1010][2],p[500010] = {0};
int Max(int a,int b){
	return a > b ? a : b;
}
int father(int x){
	if (f[x] == x) return x;
	return f[x] = father(f[x]);
}
bool prime(int x){
	for (int i = 2;i * i <= x;++i) if (x % i == 0) return 0;
	return 1;
}
vector<int> edge[1010];
void search(int x){
	vector<int> t;
	t.clear();
	int n = edge[x].size();
	for (int i = 0;i < n;++i) if (!v[edge[x][i]]){
		int y = edge[x][i];
		t.push_back(y);
		v[y] = 1;
		search(y);
	}
	edge[x] = t;
}
int work(int x,int y){
	if (vb[x][y]) return b[x][y];
	vb[x][y] = 1;
	int ret = 0;
	int n = edge[x].size();
	if (n == 0) return y;
	if (y == 0){
		for (int i = 0;i < n;++i) ret += Max(work(edge[x][i],0),work(edge[x][i],1));
	}else{
		for (int i = 0;i < n;++i) ret += work(edge[x][i],0);
		++ret;
	}
	return b[x][y] = ret;
}
int main(){
	for (int i = 2;i <= 1000;++i) if (!p[i])
		for (int j = i * 2;j <= 500000;j += i) p[j] = 1;
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%d",&n);
		for (int i = 1;i <= n;++i) edge[i].clear();
		for (int i = 1;i <= n;++i) scanf("%d",a + i);
		sort(a + 1,a + n + 1);
		for (int i = 1;i <= n;++i) f[i] = i;
		for (int i = 1;i < n;++i)
			for (int j = i + 1;j <= n;++j) if (a[j] % a[i] == 0 && !p[a[j] / a[i]]){
				edge[i].push_back(j);
				edge[j].push_back(i);
				if (father(i) != father(j)){
					int x = f[i];
					int y = f[j];
					if (x < y) f[y] = x;else f[x] = y;
				}
			}
		for (int i = 1;i <= n;++i) f[i] = father(i);
		memset(v,0,sizeof v);
		memset(vf,0,sizeof vf);
		memset(b,0,sizeof b);
		memset(vb,0,sizeof vb);
		ans = 0;
		for (int i = 1;i <= n;++i) if (!vf[f[i]]){
			vf[f[i]] = 1;
			v[f[i]] = 1;
			search(f[i]);
			ans += Max(work(f[i],0),work(f[i],1));
		}
		printf("Case #%d: %d\n",T,ans);
	}
}
