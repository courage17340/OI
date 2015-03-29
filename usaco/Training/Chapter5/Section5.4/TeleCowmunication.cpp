/*
USER: courage2
LANG: C++
TASK: telecow
*/
#include <cstdio>
#include <cstring>
const int INF = 1e8;
struct rec{int f,x,cur;};
rec b[210];
int a[210][210] = {{0}},r[210][210],n,m,k,p,c1,c2,x,y,ans[210];
bool v[210] = {0};
int min(int a,int b){
	return a < b ? a : b;
}
int max_flow(){
	int ret = 0,y,p,q;
	bool flag;
	for (int i = 1;i <= n * 2;i++)
		for (int j = 1;j <= n * 2;j++) r[i][j] = a[i][j];
	while (1){
		flag = 0;
		memset(v,0,sizeof v);
		p = q = 1;
		b[1].x = c1;
		b[1].f = 0;
		b[1].cur = INF;
		v[1] = 1;
		while (p <= q){
			if (b[p].x == c2){
				y = b[p].cur;
				for (int x = p;x != 1;x = b[x].f){
					r[b[b[x].f].x][b[x].x] -= y;
					r[b[x].x][b[b[x].f].x] += y;
				}
				ret += y;
				flag = 1;
				break;
			}
			for (int i = 1;i <= n * 2;i++) if (!v[i] && r[b[p].x][i] > 0){
				q++;
				b[q].x = i;
				b[q].f = p;
				b[q].cur = min(b[p].cur,r[b[p].x][i]);
				v[i] = 1;
			}
			p++;
		}
		if (!flag) break;
	}
	return ret;
}
int main(){
	freopen("telecow.in","r",stdin);
	freopen("telecow.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	c1 += n;
	for (int i = 1;i <= n;i++) a[i][n + i] = 1;
	while (m--){
		scanf("%d%d",&x,&y);
		a[n + x][y] = a[n + y][x] = INF;
	}
	k = max_flow();
	printf("%d\n",k);
	p = 0;
	for (int i = 1;i <= n;i++) if (i != c1 - n && i != c2){
		a[i][n + i] = 0;
		int tmp = max_flow();
		if (tmp < k){
			k = tmp;
			ans[++p] = i;
		}else a[i][n + i] = 1;
		if (!k) break;
	}
	for (int i = 1;i < p;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[p]);
}
