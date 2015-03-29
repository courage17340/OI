/*
USER: courage2
LANG:C++
TASK: fence8
*/
#include <cstdio>
#include <algorithm>
int n,m,a[51],c[51],b[1040],ans,l,r,mid,s1[51],s2[1040];
bool search(int k,int x,int waste,int delta){
	if (k == 1) return 1;
	a[x] -= b[k];
	if (a[x] < b[1]) waste += a[x];
	if (waste > delta){
		a[x] += b[k];
		return 0;
	}
	if (b[k] == b[k - 1]){
		for (int i = x;i <= n;i++) if (a[i] >= b[k - 1] && search(k - 1,i,waste,delta)) return 1;
	}else{
		for (int i = 1;i <= n;i++) if (a[i] >= b[k - 1] && search(k - 1,i,waste,delta)) return 1;
	}
	a[x] += b[k];
	return 0;
}
bool yes(){
	if (s2[mid] > s1[n]) return 0;
	int delta = s1[n] - s2[mid];
	for (int i = 1;i <= n;i++) if (a[i] >= b[mid] && search(mid,i,0,delta)) return 1;
	return 0;
}
int main(){
	freopen("fence8.in","r",stdin);
	freopen("fence8.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	scanf("%d",&m);
	for (int i = 1;i <= m;i++) scanf("%d",b + i);
	std::sort(a + 1,a + n + 1);
	std::sort(b + 1,b + m + 1);
	l = 0;
	r = m;
	for (int i = 1;i <= n;i++) c[i] = a[i];
	s1[0] = s2[0] = 0;
	for (int i = 1;i <= n;i++) s1[i] = s1[i - 1] + a[i];
	for (int i = 1;i <= m;i++) s2[i] = s2[i - 1] + b[i];
	while (l != r){
		for (int i = 1;i <= n;i++) a[i] = c[i];
		mid = (l + r + 1) >> 1;
		if (yes()) l = mid;else r = mid - 1;
	}
	printf("%d\n",l);
}
