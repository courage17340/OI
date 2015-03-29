/*
ID: courage2
LANG: C++
TASK: milk
*/
#include <cstdio>
#include <algorithm>
struct rec{int p,a;};
rec a[5010];
int n,m,ans,k;
bool cmp(rec a,rec b){
	return a.p < b.p;
}
int main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	scanf("%d%d",&m,&n);
	ans = 0;
	for (int i = 1;i <= n;i++) scanf("%d%d",&a[i].p,&a[i].a);
	std::sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++){
		k = a[i].a;
		if (k > m) k = m;
		m -= k;
		ans += k * a[i].p;
		if (m == 0) break;
	}
	printf("%d\n",ans);
}
