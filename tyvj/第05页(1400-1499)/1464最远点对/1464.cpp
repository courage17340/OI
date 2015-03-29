#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;
struct point{ll x,y;};
point a[100010],p,q;
int n,r,s,f[100010],t;
ll ans;
ll cross(point a,point b,point c){
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
inline ll mul(point a,point b){
	return (a.x * b.y - a.y * b.x);
}
inline ll abs(ll x){
	return (x > 0 ? x : -x);
}
bool yes(int i,int top){
	point p,q;
	p.x = a[i].x - a[f[top - 1]].x;
	p.y = a[i].y - a[f[top - 1]].y;
	q.x = a[f[top]].x - a[f[top - 1]].x;
	q.y = a[f[top]].y - a[f[top - 1]].y;
	return (mul(p,q) >= 0);
}
ll max(ll a,ll b){
	return a > b ? a : b;
}
ll dis(point a,point b){
	return ll(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool cmp(point a,point b){
	a.x -= p.x;
	b.x -= p.x;
	a.y -= p.y;
	b.y -= p.y;
	if (mul(a,b)) return (mul(a,b) > 0);
	return (dis(a,p) < dis(b,p));
}
int main(){
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
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
		while (r > 1 && yes(i,r)) r--;
		r++;
		f[r] = i;
	}
	f[0] = f[r];
	ans = 0;
	t = 1;
	for (int i = 0;i < r;i++){
		while (cross(a[f[i + 1]],a[f[t + 1]],a[f[i]]) > cross(a[f[i + 1]],a[f[t]],a[f[i]])){
			t++;
			if (t == r) t = 0;
		}
		ans = max(ans,dis(a[f[i]],a[f[t]]));
	}
	cout << ans;
}
