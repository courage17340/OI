/*
USER: courage2
LANG: C++
TASK: cowcycle
*/
#include <cstdio>
#include <algorithm>
int n,m,l1,r1,l2,r2;
double a[60],d[100][100];
struct rec{
	int a[6],b[11];
	double v;
	rec &operator =(const rec &x){
		if (&x == this) return *this;
		for (int i = 1;i <= n;i++) a[i] = x.a[i];
		for (int i = 1;i <= m;i++) b[i] = x.b[i];
		v = x.v;
		return *this;
	}
};
rec ans,t;
double V(const rec &b){
	int t = 0;
	for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) a[++t] = d[b.a[i]][b.b[j]];
	std::sort(a + 1,a + t + 1);
	for (int i = 1;i < t;i++) a[i] = a[i + 1] - a[i];
	t--;
	double x = 0;
	for (int i = 1;i <= t;i++) x += a[i];
	x /= t;
	double ret = 0;
	for (int i = 1;i <= t;i++) ret += (a[i] - x) * (a[i] - x);
	return ret;
}
void search(int k,int p,int x){
	if (k == 1) t.a[p] = x;else t.b[p] = x;
	if (k == 1 && p == n){
		search(2,0,l2 - 1);
		return;
	}
	if (k == 2 && p == 1){
		if (t.a[n] * r2 < 3 * t.a[1] * x) return;
	}
	if (k == 2 && p == m){
		if (t.a[n] * t.b[m] < 3 * t.a[1] * t.b[1]) return;
		t.v = V(t);
		if (t.v < ans.v * 0.999) ans = t;
		return;
	}
	for (int i = x + 1;i <= (k == 1 ? r1 : r2);i++) search(k,p + 1,i);
}
int main(){
	freopen("cowcycle.in","r",stdin);
	freopen("cowcycle.out","w",stdout);
	scanf("%d%d%d%d%d%d",&n,&m,&l1,&r1,&l2,&r2);
	for (int i = l1;i <= r1;i++) for (int j = l2;j <= r2;j++) d[i][j] = i * 1.0 / j;
	ans.v = 1e10;
	search(1,0,l1 - 1);
	for (int i = 1;i < n;i++) printf("%d ",ans.a[i]);
	printf("%d\n",ans.a[n]);
	for (int i = 1;i < m;i++) printf("%d ",ans.b[i]);
	printf("%d\n",ans.b[m]);
}
