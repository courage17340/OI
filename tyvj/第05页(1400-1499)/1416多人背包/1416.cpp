#include <cstdio>
#include <cstring>
#include <algorithm>
int a[110],k,v,n,x,y,z,f[51][5010],ans,p;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	scanf("%d%d%d",&k,&v,&n);
	memset(f,-1,sizeof f);
	f[1][0] = 0;
	while (n--){
		scanf("%d%d",&x,&y);
		if (x > v) continue;
		for (int i = v;i >= x;i--){
			p = 0;
			for (int j = 1;j <= k;j++) if (f[j][i - x] >= 0 && f[j][i - x] + y > f[k][i]) a[++p] = f[j][i - x] + y;
			for (int j = 1;j <= k;j++) a[++p] = f[j][i];
			std::sort(a + 1,a + p + 1,cmp);
			for (int j = 1;j <= k && j <= p;j++) f[j][i] = a[j];
		}
	}
	ans = 0;
	for (int i = 1;i <= k;i++) ans += f[i][v];
	printf("%d\n",ans);
}
