/*
USER: courage2
LANG: C++
TASK: wormhole
*/
#include <cstdio>
#include <cstring>
int x[20],y[20],n,co[20] = {0},ans = 0;
bool v[20] = {0};
bool check(){
	for (int i = 1;i <= n;i++){
		int ix = x[i] - 1;
		int iy = y[i];
		int cur = 1;
		memset(v,0,sizeof v);
		while (cur){
			cur = 0;
			for (int j = 1;j <= n;j++) if (x[j] > ix && y[j] == iy)
				if (!cur || x[j] < x[cur]) cur = j;
			if (cur){
				if (v[cur]) return 1;
				v[cur] = 1;
				ix = x[co[cur]];
				iy = y[co[cur]];
			}
		}
	}
	return 0;
}
void search(int k,int x,int y){
	co[x] = y;
	co[y] = x;
	if (k * 2 == n){
		if (check()) ans++;
		co[x] = co[y] = 0;
		return;
	}
	int t = x + 1;
	while (t < n && co[t]) t++;
	for (int i = t + 1;i <= n;i++) if (!co[i]) search(k + 1,t,i);
	co[x] = co[y] = 0;
}
int main(){
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d%d",x + i,y + i);
	search(0,0,0);
	printf("%d\n",ans);
}
