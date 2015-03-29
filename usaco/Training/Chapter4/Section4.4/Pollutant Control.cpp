/*
USER: courage2
LANG: C++
TASK: milk6
*/
#include <cstdio>
#include <cstring>
typedef long long ll;
ll a[33][33] = {{0}},r[33][33],ans,current;
int n,m,num,k,x,y,an[1010],p = 0;
struct rec{int x,y,z;};
struct node{int f,x;ll cur;};
rec e[1010];
node b[34];
bool v[33];
template <class T>
T min(T a,T b){
	return a < b ? a : b;
}
ll maxStream(){
	ll ret = 0,y;
	bool flag;
	int p,q;
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) r[i][j] = a[i][j];
	while (1){
		memset(v,0,sizeof v);
		flag = 0;
		p = q = 1;
		b[1].x = 1;
		b[1].f = 0;
		b[1].cur = 1e10;
		v[1] = 1;
		while (p <= q){
			if (b[p].x == n){
				y = b[p].cur;
				for (int x = p;x != 1;x = b[x].f){
					r[b[b[x].f].x][b[x].x] -= y;
					r[b[x].x][b[b[x].f].x] += y;
				}
				ret += y;
				flag = 1;
				break;
			}
			for (int i = 1;i <= n;i++) if (!v[i] && r[b[p].x][i] > 0){
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
	freopen("milk6.in","r",stdin);
	freopen("milk6.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
		e[i].z = e[i].z * (m + 1) + 1;
		a[e[i].x][e[i].y] += e[i].z;
	}
	ans = maxStream();
	x = ans / (m + 1);
	num = ans % (m + 1);
	printf("%d %d\n",x,num);
	
	for (int i = 1;i <= m;i++){
		a[e[i].x][e[i].y] -= e[i].z;
		if (maxStream() + e[i].z == ans){
			ans -= e[i].z;
			an[++p] = i;
		}else a[e[i].x][e[i].y] += e[i].z;
		if (p == num) break;
	}
	for (int i = 1;i <= p;i++) printf("%d\n",an[i]);
}
