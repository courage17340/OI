/*
USER: courage2
LANG: C++
TASK: spin
*/
#include <cstdio>
#include <cstring>
int v[6],k[6],x[6][6],y[6][6],p,s[6] = {0};
bool f[360],g[360];
int main(){
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	for (int i = 1;i <= 5;i++){
		scanf("%d%d",v + i,k + i);
		for (int j = 1;j <= k[i];j++) scanf("%d%d",&x[i][j],&y[i][j]);
	}
	for (int t = 0;t <= 359;t++){
		memset(g,1,sizeof g);
		for (int i = 1;i <= 5;i++){
			memset(f,0,sizeof f);
			for (int j = 1;j <= k[i];j++){
				p = x[i][j] + s[i];
				p %= 360;
				for (int r = 0;r <= y[i][j];r++){
					f[p] = 1;
					p++;
					if (p > 359) p = 0;
				}
			}
			for (int i = 0;i < 360;i++) g[i] &= f[i];
		}
		for (int i = 0;i < 360;i++) if (g[i]){
			printf("%d\n",t);
			return 0;
		}
		for (int i = 1;i <= 5;i++) s[i] += v[i];
	}
	puts("none");
}
