/*
USER: courage2
LANG: C++
TASK: fc
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
const double eps = 1e-6;
struct point{double x,y;};
point a[100010],p,q;
int n,r,s,f[100010];
double ans;
inline double mul(point a,point b){
	return (a.x * b.y - a.y * b.x);
}
double d(point a,point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmp(point a,point b){
	a.x -= p.x;
	b.x -= p.x;
	a.y -= p.y;
	b.y -= p.y;
	if (fabs(mul(a,b)) > eps) return (mul(a,b) > 0);
	return (d(a,p) < d(b,p));
}
bool yes(int i,int top){
	point p,q;
	p.x = a[i].x - a[f[top - 1]].x;
	p.y = a[i].y - a[f[top - 1]].y;
	q.x = a[f[top]].x - a[f[top - 1]].x;
	q.y = a[f[top]].y - a[f[top - 1]].y;
	return (mul(p,q) >= 0);
}
int main(){
	freopen("fc.in","r",stdin);
	freopen("fc.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	for (int i = 2;i <= n;i++) if (a[i].y < a[1].y || (a[i].y == a[1].y && a[i].x < a[1].x)){
		p = a[i];
		a[i] = a[1];
		a[1] = p;
	}
	p = a[1];
	std::sort(a + 2,a + n + 1,cmp);
	f[1] = 1;
	f[2] = 2;
	f[3] = 3;
	r = 3;
	for (int i = 4;i <= n;i++){
		while (yes(i,r)) r--;
		r++;
		f[r] = i;
	}
	ans = d(a[f[1]],a[f[r]]);
	for (int i = 1;i < r;i++) ans += d(a[f[i]],a[f[i + 1]]);
	printf("%.2f\n",ans);
}
