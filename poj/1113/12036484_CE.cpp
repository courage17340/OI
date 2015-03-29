#include<cstdio>
#include<cmath>
#include<algorithm>
struct point{double x,y;};
point a[1010],p,q;
int n,r,s,f[1010],l;
double ans=0;
inline double sqr(double x){
	return x*x;
}
inline double mul(point a,point b){
	return (a.x*b.y-a.y*b.x);
}
inline double abs(double x){
	return (x>0?x:-x);
}
bool cmp(point a,point b){
	a.x-=p.x;
	b.x-=p.x;
	a.y-=p.y;
	b.y-=p.y;
	if (abs(mul(a,b))>1e-8) return (mul(a,b)>0);
	return (abs(a.x)>abs(b.x));
}
bool yes(int i,int top){
	point p,q;
	p.x=a[i].x-a[f[top-1]].x;
	p.y=a[i].y-a[f[top-1]].y;
	q.x=a[f[top]].x-a[f[top-1]].x;
	q.y=a[f[top]].y-a[f[top-1]].y;
	return (mul(p,q)>=0);
}
int main(){
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	for (int i=2;i<=n;i++) if (a[i].y<a[1].y || (a[i].y==a[1].y && a[i].x<a[1].x)){
		p=a[i];
		a[i]=a[1];
		a[1]=p;
	}
	p=a[1];
	std::sort(a+2,a+n+1,cmp);
	f[1]=1;
	f[2]=2;
	f[3]=3;
	r=3;
	for (int i=4;i<=n;i++){
		while (yes(i,r)&&r>1) r--;
		r++;
		f[r]=i;
	}
	for (int i=1;i<r;i++) ans+=sqrt(sqr(a[f[i]].x-a[f[i+1]].x)+sqr(a[f[i]].y-a[f[i+1]].y));
	ans+=sqrt(sqr(a[f[1]].x-a[f[r]].x)+sqr(a[f[1]].y-a[f[r]].y));
	ans+=3.14159265*2*l;
	printf("%.0lf",ans);
}