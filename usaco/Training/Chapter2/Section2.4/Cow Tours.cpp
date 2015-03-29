/*
ID: courage2
TASK: cowtour
LANG: C++
*/
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int x[160],y[160],b[160],f[160],n,m,p,q,r;
bool v[160][160];
double d[160][160],ans,g[160],tmp;
vector <int> a[160];
char s[160];
double dis(int i,int j){
	return sqrt((0.0 + x[i] - x[j]) * (x[i] - x[j]) + (0.0 + y[i] - y[j]) * (y[i] - y[j]));
}
int father(int x){
	if (f[x] == x) return x;
	return f[x] = father(f[x]);
}
double max(double a,double b){
	return a > b ? a : b;
}
double min(double a,double b){
	return a < b ? a : b;
}
int main(){
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d%d",x + i,y + i);
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= n;i++){
		scanf("%s",s);
		for (int j = 0;j < n;j++) if (s[j] == '1'){
			d[i][j + 1] = dis(i,j + 1);
			if (father(i) != father(j + 1)) f[f[i]] = f[j + 1];
		}else d[i][j + 1] = 1e10;
	}
	for (int i = 1;i <= n;i++) d[i][i] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) if (d[i][j] < 1e7 && father(i) != father(j)){
			f[f[i]] = f[j];
		}
	m = 0;
	for (int i = 1;i <= n;i++) if (f[i] == i){
		m++;
		for (int j = 1;j <= n;j++) if (father(j) == i) a[m].push_back(j);
		b[m] = a[m].size();
	}
	for (int t = 1;t <= m;t++){
		for (int k = 0;k < b[t];k++)
			for (int i = 0;i < b[t];i++)
				for (int j = 0;j < b[t];j++) if (i != j){
					p = a[t][i];
					q = a[t][j];
					r = a[t][k];
					d[p][q] = min(d[p][q],d[p][r] + d[r][q]);
				}
		if (b[t] == 1){
			g[a[t][0]] = 0;
			continue;
		}
		for (int i = 0;i < b[t];i++){
			p = a[t][i];
			g[p] = 0;
			for (int j = 0;j < b[t];j++) if (i != j) g[p] = max(g[p],d[p][a[t][j]]);
		}
	}
	ans = 1e10;
	for (int i = 1;i < m;i++)
		for (int j = i + 1;j <= m;j++){
			tmp = 0;
			for (int k = 0;k < b[i];k++) tmp = max(tmp,g[a[i][k]]);
			for (int k = 0;k < b[j];k++) tmp = max(tmp,g[a[j][k]]);
			double t = 1e10;
			for (int k = 0;k < b[i];k++)
				for (int r = 0;r < b[j];r++) t = min(t,dis(a[i][k],a[j][r]) + g[a[i][k]] + g[a[j][r]]);
			tmp = max(tmp,t);
			ans = min(ans,tmp);
		}
	printf("%.6f\n",ans);
}
