#include <cstdio>
#include <algorithm>
#include <cmath>
struct rec{double x,y,z;};
struct ed{int x,y;double z;};
rec a[1010];
ed b[500010];
int n,m,f[1010];
double ans;
inline double sqr(double x){
	return x * x;
}
bool cmp(ed a,ed b){
	return a.z < b.z;
}
int father(int x){
	if (f[x] == x) return x;
	f[x] = father(f[x]);
	return f[x];
}
int main(){
	n = 1;
	a[1].x = a[1].y = a[1].z = -1;
	while (scanf("%lf%lf%lf",&a[n + 1].x,&a[n + 1].y,&a[n + 1].z) != EOF) n++;
	m = 0;
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i < n;i++)
		for (int j = i + 1;j <= n;j++){
			m++;
			b[m].x = i;
			b[m].y = j;
			b[m].z = sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y) + sqr(a[i].z - a[j].z));
		}
	std::sort(b + 1,b + m + 1,cmp);
	ans = 0;
	for (int i = 1;i <= m;i++) if (father(b[i].x) != father(b[i].y)){
		ans += b[i].z;
		f[f[b[i].x]] = f[b[i].y];
	}
	printf("%.4f",ans);
}
