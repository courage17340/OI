#include <cstdio>
#include <algorithm>
int n,m,a[100010],x,l,r;
long long ans = 0;
bool cmp(int a,int b){
	return a > b;
}
bool yes(int x){
	long long y = (long long)x * (x - 1) / 2;
	if (x & 1) y++;else y += x / 2;
	return (y <= n);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
		scanf("%d%d",&x,&a[i]);
	std::sort(a + 1,a + m + 1,cmp);
	l = 1;
	r = m;
	while (l < r){
		x = (l + r + 1) >> 1;
		if (yes(x)) l = x;else r = x - 1;
	}
	for (int i = 1;i <= l;i++) ans += a[i];
	printf("%I64d",ans);
}
