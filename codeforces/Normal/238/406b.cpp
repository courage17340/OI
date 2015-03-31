#include <cstdio>
#include <algorithm>
inline int min(int a,int b){
	return a < b ? a : b;
}
inline int d(int x){
	return min(x - 1,1000000 - x);
}
bool cmp(int a,int b){
	if (a + b == 1000001) return a < b;
	return d(a) < d(b);
}
int a[500010],b[500010],p,q,r,ans[500010],k = 0,n;
bool y[500010] = {0};
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	printf("%d\n",n);
	std::sort(a + 1,a + n + 1,cmp);
	r = 0;
	p = 1;
	while (p <= n){
		if (p < n && d(a[p]) != d(a[p + 1])){
			ans[++r] = 1000001 - a[p];
			y[min(a[p],1000001 - a[p])] = 1;
			p++;
			continue;
		}
		if (p < n && d(a[p]) == d(a[p + 1])){
			k++;
			y[min(a[p],1000001 - a[p])] = 1;
			p += 2;
			continue;
		}
		ans[++r] = 1000001 - a[p];
		p++;
	}
	p = 0;
	while (k){
		p++;
		while (y[p]) p++;
		ans[++r] = p;
		ans[++r] = 1000001 - p;
		k--;
	}
	for (int i = 1;i < n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
}
