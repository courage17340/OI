/*
USER: courage2
LANG:C++
TASK: fence6
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> V,l[210];
int n,m,p,q,t,x,y,z,n1,n2,a[210][210],f[210],num[2][110],d[110],e[110],ans;
bool v[210] = {0};
int father(int x){
	if (f[x] == x) return x;
	return f[x] = father(f[x]);
}
void merge(int x,int y){
	if (father(x) != father(y)) f[f[y]] = f[x];
}
int main(){
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	scanf("%d",&m);
	memset(a,1,sizeof a);
	for (int i = 1;i <= m;i++){
		num[0][i] = i * 2 - 1;
		num[1][i] = i * 2;
	}
	for (int i = 1;i <= m;i++){
		scanf("%d",&x);
		scanf("%d%d%d",&e[x],&y,&z);
		for (int j = 1;j <= y;j++){
			scanf("%d",&t);
			l[num[0][x]].push_back(t);
		}
		for (int j = 1;j <= z;j++){
			scanf("%d",&t);
			l[num[1][x]].push_back(t);
		}
	}
	for (int i = 1;i <= m * 2;i++) f[i] = i;
	for (int i = 1;i <= m * 2;i++){
		x = (i + 1) >> 1;
		for (int j = 0;j < l[i].size();j++){
			y = l[i][j];
			for (int k = y * 2 - 1;k <= y * 2;k++)
				for (int r = 0;r < l[k].size();r++) if (l[k][r] == x){
					merge(i,k);
				}
		}
	}
	for (int i = 1;i <= m * 2;i++) v[father(i)] = 1;
	for (int i = 1;i <= m * 2;i++) if (v[i]) V.push_back(i);
	n = V.size();
	for (int i = 1;i <= m;i++) num[0][i] = (lower_bound(V.begin(),V.end(),father(num[0][i])) - V.begin()) + 1;
	for (int i = 1;i <= m;i++) num[1][i] = (lower_bound(V.begin(),V.end(),father(num[1][i])) - V.begin()) + 1;
	for (int i = 1;i <= m;i++) a[num[0][i]][num[1][i]] = a[num[1][i]][num[0][i]] = e[i];
	for (int i = 1;i <= n;i++) a[i][i] = 0;
	ans = 2e9;
	for (int i = 1;i <= m;i++){
		x = num[0][i];
		y = num[1][i];
		z = e[i];
		a[x][y] = a[y][x] = 1e9;
		for (int j = 1;j <= m;j++) d[j] = a[x][j];
		memset(v,0,sizeof v);
		v[x] = 1;
		d[0] = 1.1e9;
		for (int k = 1;k < n;k++){
			p = 0;
			for (int j = 1;j <= n;j++) if (!v[j] && d[j] < d[p]) p = j;
			v[p] = 1;
			for (int j = 1;j <= n;j++) if (d[j] > d[p] + a[p][j]) d[j] = d[p] + a[p][j];
		}
		if (ans > z + d[y]) ans = z + d[y];
	}
	printf("%d\n",ans);
}
