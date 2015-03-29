/*
ID: courage2
PROG: milk2
LANG: C++
*/
#include <cstdio>
#include <algorithm>
struct rec{int x,y;};
rec a[5010];
int n,ans,x,y,p,q,ans2;
bool cmp(rec a,rec b){
	return (a.x < b.x);
}
int main(){
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(a + 1,a + n + 1,cmp);
	p = q = 1;
	ans = 0;
	ans2 = 0;
	x = a[1].x;
	y = a[1].y;
	while (p <= n){
		while (q < n && a[q+1].x <= y){
			if (y < a[q + 1].y) y = a[q + 1].y;
			q++;
		}
		if (ans < y - x) ans = y - x;
		q++;
		p = q;
		if (p <= n){
			if (ans2 < a[p].x - y) ans2 = a[p].x - y;
			x = a[p].x;
			y = a[p].y;
		}
	}
	printf("%d %d\n",ans,ans2);
}
