#include <cstdio>
#include <algorithm>
int a[100010],l,r,ans,n,m;
long long s = 0;
int f(int x,int y){
	int k = x / y;
	if (x % y) k++;
	return k;
}
bool yes(int x){
	long long k = 0;
	for (int i = 1;i <= n;i++){
		k += f(a[i],x);
		if (k > m) return 0;
	}
	return 1;	
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	std::sort(a + 1,a + n + 1);
	r = a[n] / (m / n) + 1;
	for (int i = 1;i <= n;i++) s += a[i];
	l = s / m;
	while (l != r){
		ans = (l + r) >> 1;
		if (yes(ans)) r = ans;else l = ans + 1;
	}
	printf("%d\n",l);
}
