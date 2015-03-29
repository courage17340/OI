#include <cstdio>
#include <algorithm>
int a[100010],b[100010],n,m,ans,p;
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int j = 1;j <= m;j++) scanf("%d",&b[j]);
	std::sort(a + 1,a + n + 1);
	std::sort(b + 1,b + m + 1);
	a[0] = -1e9;
	a[n + 1] = 1e9;
	p = ans = 0;
	for (int i = 1;i <= m;i++){
		while (b[i] > a[p + 1]) p++;
		ans += min(b[i] - a[p],a[p + 1] - b[i]);
	}
	printf("%d\n",ans);
}
