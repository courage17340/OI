#include <cstdio>
#include <list>
#include <vector>
using namespace std;
struct rec{
	int x,y;
	rec(int X = 0,int Y = 0):x(X),y(Y){}
};
list <rec> f;
vector <rec> g;
int a[1010][1010],n,m,ans1,ans2,x,y,h,k1,k2;
bool v[1010][1010] = {{0}};
int main(){
	scanf("%d",&n);
	ans1 = ans2 = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) scanf("%d",&a[i][j]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) if (!v[i][j]){
			f.clear();
			g.clear();
			f.push_back(rec(i,j));
			g.push_back(rec(i,j));
			h = a[i][j];
			v[i][j] = 1;
			while (!f.empty()){
				x = f.front().x;
				y = f.front().y;
				for (int p = x - 1;p <= x + 1;p++)
					for (int q = y - 1;q <= y + 1;q++)
						if (0 < p && p <= n && 0 < q && q <= n && !v[p][q] && a[p][q] == h){
							v[p][q] = 1;
							f.push_back(rec(p,q));
							g.push_back(rec(p,q));
						}
				f.pop_front();
			}
			m = g.size();
			k1 = k2 = 0;
			for (int t = 0;t < m;t++)
				for (int p = g[t].x - 1;p <= g[t].x + 1;p++)
					for (int q = g[t].y - 1;q <= g[t].y + 1;q++) if (0 < p && p <= n && 0 < q && q <= n){
						if (a[p][q] > h) k1++;
						if (a[p][q] < h) k2++;
					}
			if (k1 == 0) ans1++;
			if (k2 == 0) ans2++;
		}
	printf("%d %d\n",ans1,ans2);
}
