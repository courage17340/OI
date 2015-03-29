/*
USER: courage2
LANG: C++
TASK: job
*/
#include <cstdio>
#include <cstring>
int n,p,m1,m2,a[31],b[31],d[31],c[1010] = {0},ans;
int main(){
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i = 1;i <= m1;i++) scanf("%d",a + i);
	for (int i = 1;i <= m2;i++) scanf("%d",b + i);
	memset(d,0,sizeof d);
	for (int i = 1;i <= n;i++){
		p = 1;
		for (int j = 2;j <= m1;j++) if (a[j] + d[j] < a[p] + d[p]) p = j;
		c[i] = a[p] + d[p];
		d[p] = c[i];
	}
	printf("%d",c[n]);
	memset(d,0,sizeof d);
	for (int i = n;i >= 1;i--){
		p = 1;
		for (int j = 2;j <= m2;j++) if (b[j] + d[j] < b[p] + d[p]) p = j;
		c[i] += (b[p] + d[p]);
		d[p] += b[p];
	}
	ans = 0;
	for (int i = 1;i <= n;i++) if (ans < c[i]) ans = c[i];
	printf(" %d\n",ans);
}
