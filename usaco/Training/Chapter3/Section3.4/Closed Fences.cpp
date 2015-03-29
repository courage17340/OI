/*
USER: courage2
LANG:C++
TASK: fence4
*/
#include <cstdio>
#include <cmath>
const double pi = atan(1.0) * 4;
const int N = 233;
template <class T>
struct point{
	T x,y;
	point(T X = 0,T Y = 0):x(X),y(Y){}
	point operator -(const point<T> &a){
		point<T> b;
		b.x = x - a.x;
		b.y = y - a.y;
		return b;
	}
	T operator *(const point<T> &a){
		return x * a.y - y * a.x;
	}
};
point <int>a[210];
point <double>r;
struct seg{
	point<int> p[2];
	int x[2];
};
seg c[210],ans[210],q;
int n,m;
double xx,yy,x2,y2,x3,y3;
template <class T>
void swap(T &a,T &b){
	T t;
	t = a;
	a = b;
	b = t;
}
int flag(double x){
	if (fabs(x) < 1e-7) return 0;
	if (x < 0) return -1;
	return 1;
}
template <class T>
bool cross(point<T> a,point<T> b,point<T> c,point<T> d){
	T x1,x2,y1,y2;
	x1 = (a - c) * (c - d);
	y1 = (b - c) * (c - d);
	x2 = (c - a) * (a - b);
	y2 = (d - a) * (a - b);
	return flag(x1) * flag(y1) < 0 && flag(x2) * flag(y2) < 0;
}
int ne(int x){
	x++;
	if (x > n) x = 1;
	return x;
}
int main(){
	freopen("fence4.in","r",stdin);
	freopen("fence4.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0;i <= n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i = 1;i <= n;i++)
		for (int j = ne(ne(i));ne(j) != i;j = ne(j)) if (cross(a[i],a[ne(i)],a[j],a[ne(j)])){
			puts("NOFENCE");
			return 0;
		}
	for (int i = 1;i < n - 1;i++){
		c[i].p[0] = a[i];
		c[i].p[1] = a[i + 1];
	}
	c[n - 1].p[0] = a[1];
	c[n - 1].p[1] = a[n];
	c[n].p[0] = a[n - 1];
	c[n].p[1] = a[n];
	m = 0;
	for (int i = 1;i <= n;i++){
		if ((c[i].p[0] - a[0]) * (c[i].p[1] - a[0]) == 0) continue;
		int count = 0;
		xx = c[i].p[0].x;
		yy = c[i].p[0].y;
		x2 = (c[i].p[1].x - xx) / N;
		y2 = (c[i].p[1].y - yy) / N;
		for (double x = xx + x2,y = yy + y2,k = 1;k < N;x += x2,y += y2,k++){
			bool f = 1;
			for (int j = 1;j <= n;j++) if (i != j){
				if (cross(point<double>(a[0].x,a[0].y),point<double>(x,y),point<double>(c[j].p[0].x + 0.0,c[j].p[0].y + 0.0),point<double>(c[j].p[1].x + 0.0,c[j].p[1].y + 0.0))){
					f = 0;
					break;
				}
			}
			count += f;
		}
		if (count >= 1){
			ans[++m] = c[i];
		}
	}
	printf("%d\n",m);
	for (int i = 1;i <= m;i++) printf("%d %d %d %d\n",ans[i].p[0].x,ans[i].p[0].y,ans[i].p[1].x,ans[i].p[1].y);
}
