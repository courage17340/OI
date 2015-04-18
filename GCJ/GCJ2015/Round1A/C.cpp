#include <cstdio>
#include <algorithm>
typedef long long ll;
struct point{ll x,y;};
point a[110],p,q;
int t,n,r,s,f[110],list[110],ans[110],x[110],y[110];
inline ll mul(point a,point b){
	return (a.x * b.y - a.y * b.x);
}
inline ll abs(ll x){
	return (x > 0 ? x : -x);
}
template <class T>
T min(T a,T b){
	return a < b ? a : b;
}
bool cmp(point a,point b){
	a.x -= p.x;
	b.x -= p.x;
	a.y -= p.y;
	b.y -= p.y;
	if (mul(a,b)) return (mul(a,b) > 0);
	return (abs(a.x - p.x) + abs(a.y - p.y) < abs(b.x - p.x) + abs(b.y - p.y));
}
bool yes(int i,int top){
	point p,q;
	p.x = a[i].x - a[f[top - 1]].x;
	p.y = a[i].y - a[f[top - 1]].y;
	q.x = a[f[top]].x - a[f[top - 1]].x;
	q.y = a[f[top]].y - a[f[top - 1]].y;
	return (mul(p,q) >= 0);
}
bool line(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
	if (x3 == x1 && y3 == y1) return 1;
	if (x3 == x2 && y3 == y2) return 1;
	ll dx1 = x3 - x1;
	ll dy1 = y3 - y1;
	ll dx2 = x2 - x3;
	ll dy2 = y2 - y3;
	if (dx1 * dy2 != dx2 * dy1) return 0;
	if (dx1 * dx2 < 0 || dy1 * dy2 < 0) return 0;
	return 1;
}
void work(int k,int pt){
	list[k] = pt;
	for (int i = 1;i <= k;++i){
		a[i].x = x[list[i]];
		a[i].y = y[list[i]];
	}
	if (k <= 3){
		//nop
	}else{
		for (int i = 2;i <= k;++i) if (a[i].y < a[1].y || (a[i].y == a[1].y && a[i].x < a[1].x)){
			p = a[i];
			a[i] = a[1];
			a[1] = p;
		}
		p = a[1];
		std::sort(a + 2,a + k + 1,cmp);
		f[1] = 1;
		f[2] = 2;
		f[3] = 3;
		r = 3;
		for (int i = 4;i <= k;++i){
			while (r > 1 && yes(i,r)) --r;
			++r;
			f[r] = i;
		}
		f[r + 1] = f[1];
		for (int i = 1;i <= r;++i){
			ll x1 = a[f[i]].x;
			ll y1 = a[f[i]].y;
			ll x2 = a[f[i + 1]].x;
			ll y2 = a[f[i + 1]].y;
			for (int j = 1;j <= n;++j){
				ll x3 = x[j];
				ll y3 = y[j];
				if (line(x1,y1,x2,y2,x3,y3)) ans[j] = min(ans[j],n - k);
			}
		}
	}
	for (int i = pt + 1;i <= n;++i) work(k + 1,i);
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%d",&n);
		for (int i = 1;i <= n;++i) scanf("%d%d",&x[i],&y[i]);
		for (int i = 1;i <= n;++i) ans[i] = n - 3;
		if (n - 3 < 0) for (int i = 1;i <= n;++i) ans[i] = 0;
		for (int i = 1;i <= n;++i) work(1,i);
		printf("Case #%d:\n",T);
		for (int i = 1;i <= n;++i) printf("%d\n",ans[i]);
	}
}
