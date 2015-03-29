/*
USER: courage2
LANG: C++
TASK: rockers
*/
#include <cstdio>
int n,t,m,a[21],f[21][21][21] = {{{0}}},ans = 0;
void search(int k,int x,int y,int p){
	if (p > m) return;
	if (ans < y) ans = y;
	for (int i = k + 1;i <= n;i++) if (x >= a[i]) search(i,x - a[i],y + 1,p);
	for (int i = k + 1;i <= n;i++) if (t >= a[i]) search(i,t - a[i],y + 1,p + 1);
}
int main(){
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);
	scanf("%d%d%d",&n,&t,&m);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	search(0,t,0,1);
	printf("%d\n",ans);
}
