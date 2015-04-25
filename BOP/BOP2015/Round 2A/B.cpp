#include <cstdio>
#include <cstring>
#include <algorithm>
struct rec{
	int x,y,w;
};
rec a[1010];
bool cmp(rec a,rec b){
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
int Sqr(int x){
	return x * x;
}
int Max(int a,int b){
	return a > b ? a : b;
}
int Min(int a,int b){
	return a < b ? a : b;
}
int f[1010][3010],t,x,y,n,mx,mi,ans;
int main(){
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%d",&n);
		mx = 0;
		mi = 3000;
		ans = 0;
		for (int i = 1;i <= n;++i){
			scanf("%d%d%d",&x,&y,&a[i].w);
			a[i].x = x - y + 1000;
			a[i].y = x + y + 1000;
			mx = Max(mx,a[i].y);
			mi = Min(mi,a[i].x);
		}
		std::sort(a + 1,a + n + 1,cmp);
		memset(f,128,sizeof f);
		f[0][mi] = 0;
		for (int i = 1;i <= n;++i){
			for (int j = mi;j <= mx;++j)
				f[i][j] = f[i - 1][j];
			for (int j = mi;j <= mx;++j){
				int r = Max(j,a[i].y),cost;
				if (a[i].y <= j)
					cost = 0;
				else if (a[i].x >= j)
					cost = Sqr(a[i].y - a[i].x);
				else
					cost = Sqr(a[i].y - a[i].x) - Sqr(j - a[i].x);
				f[i][r] = Max(f[i][r],f[i - 1][j] - cost + 4 * a[i].w);
				ans = Max(ans,f[i][r]);
			}
		}
		printf("Case #%d: %.2f\n",T,(double)ans / 4);
	}
}
