/*
USER: courage2
LANG: C++
TASK: ariprog
*/
#include <cstdio>
#include <algorithm>
bool f[130010] = {0},g,h = 1;
int n,m,x,a[100010],p = 0,q = 0,k;
struct rec{int x,y;};
rec b[100010];
bool cmp(rec a,rec b){
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}
int main(){
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 0;i <= m;i++) for (int j = 0;j <= m;j++) f[i * i + j * j] = 1;
	m = m * m * 2;
	for (int i = 0;i <= m;i++) if (f[i]) a[++p] = i;
	for (int i = 1;i + n - 1 <= p;i++)
		for (int j = i + 1;j + n - 2 <= p;j++){
			k = a[j] - a[i];
			if (a[i] + (n - 1) * k > a[p]) break;
			g = 1;
			for (int t = a[i] + k,r = 1;r < n;r++,t += k) if (!f[t]){
				g = 0;
				break;
			}
			if (g){
				h = 0;
				q++;
				b[q].x = a[i];
				b[q].y = k;
			}
		}
	std::sort(b + 1,b + q + 1,cmp);
	for (int i = 1;i <= q;i++) printf("%d %d\n",b[i].x,b[i].y);
	if (h) printf("NONE\n");
}
