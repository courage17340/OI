/*
USER: courage2
LANG:C++
TASK: ditch
*/
#include <cstdio>
#include <cstring>
struct rec{int x,f;};
rec b[210];
int x,y,z,n,m,p,q,a[210][210] = {{0}},r[210][210],ans = 0;
bool v[210],flag;
int main(){
	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y] += z;
	}
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) r[i][j] = a[i][j];
	while (1){
		flag = 0;
		p = q = 1;
		memset(v,0,sizeof v);
		b[1].x = 1;
		b[1].f = 0;
		v[1] = 1;
		while (p <= q){
			if (b[p].x == n){
				x = p;
				y = r[b[b[x].f].x][b[x].x];
				while (x != 1){
					if (y > r[b[b[x].f].x][b[x].x]) y = r[b[b[x].f].x][b[x].x];
					x = b[x].f;
				}
				for (int x = p;x != 1;x = b[x].f){
					r[b[b[x].f].x][b[x].x] -= y;
					r[b[x].x][b[b[x].f].x] += y;
				}
				ans += y;
				flag = 1;
				break;
			}
			for (int i = 1;i <= n;i++) if (!v[i] && r[b[p].x][i] > 0){
				q++;
				b[q].x = i;
				b[q].f = p;
				v[i] = 1;
			}
			p++;
		}
		if (!flag) break;
	}
	printf("%d\n",ans);
}
