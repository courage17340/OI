/*
ID: courage2
LANG: C++
PROG: barn1
*/
#include <cstdio>
#include <algorithm>
int n,m,k,a[210],b[210],p,ans;
bool cmp(int a,int b){
	return (a > b);
}
int main(){
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	p = 0;
	for (int i = 1;i <= k;i++) scanf("%d",&a[i]);
	std::sort(a + 1,a + k + 1);
	for (int i = 1;i < k;i++) if (a[i + 1] - a[i] > 1) b[++p] = a[i + 1] - a[i] - 1;
	std::sort(b + 1,b + p + 1,cmp);
	ans = a[k] - a[1] + 1;
	for (int i = 1;i <= p && i < n;i++) ans -= b[i];
	printf("%d\n",ans);
}
