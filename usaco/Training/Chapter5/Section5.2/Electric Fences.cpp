/*
USER: courage2
LANG: C++
TASK: fence3
*/
#include <cmath>
#include <cstdlib>
#include <cstdio>
struct line{int x1,y1,x2,y2;};
line a[151];
int n,p;
const double pi = 4 * atan(1);
double ans[110],s,xx[110],yy[110],x,y,step,degree;
template <class T>
void swap(T &a,T &b){
	T t = a;
	a = b;
	b = t;
}
template <class T>
T min(T a,T b){
	return a < b ? a : b;
}
double d(const line &a,double x,double y){
	double dx,dy;
	if (a.x1 == a.x2){
		if (a.y1 <= y && y <= a.y2) return fabs(x - a.x1);
		dx = fabs(x - a.x1);
		dy = min(fabs(y - a.y1),fabs(y - a.y2));
		return sqrt(dx * dx + dy * dy);
	}
	if (a.x1 <= x && x <= a.x2) return fabs(y - a.y1);
	dx = min(fabs(x - a.x1),fabs(x - a.x2));
	dy = fabs(y - a.y1);
	return sqrt(dx * dx + dy * dy);
}
double f(double x,double y){
	double ret = 0;
	for (int i = 1;i <= n;i++) ret += d(a[i],x,y);
	return ret;
}
int main(){
	freopen("fence3.in","r",stdin);
	freopen("fence3.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		if (a[i].x1 > a[i].x2) swap(a[i].x1,a[i].x2);
		if (a[i].y1 > a[i].y2) swap(a[i].y1,a[i].y2);
	}
	srand(f(0,0));
	for (int k = 1;k <= 100;k++){
		xx[k] = 100.0 * rand() / RAND_MAX;
		yy[k] = 100.0 * rand() / RAND_MAX;
		ans[k] = f(xx[k],yy[k]);
		step = 50;
		while (step > 1e-2){
			degree = (double)rand() / RAND_MAX * 2 * pi;
			x = xx[k] + step * cos(degree);
			y = yy[k] + step * sin(degree);
			double t = f(x,y);
			if (t < ans[k]){
				ans[k] = t;
				xx[k] = x;
				yy[k] = y;
			}
			step *= 0.9;
		}
	}
	p = 1;
	for (int i = 2;i <= 100;i++) if (ans[i] < ans[p]) p = i;
	printf("%.1f %.1f %.1f\n",xx[p],yy[p],ans[p]);
}
