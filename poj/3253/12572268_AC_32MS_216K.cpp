#include <cstdio>
int a[20010],n,m;
long long ans = 0;
void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}
void ud(int x){
	if (x * 2 > n) return;
	int k = x;
	if (a[k] > a[x * 2]) k = x * 2;
	if (x * 2 + 1 <= n && a[k] > a[x * 2 + 1]) k = x * 2 + 1;
	if (k == x) return;
	swap(a[x],a[k]);
	ud(k);
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = n >> 1;i >= 1;i--) ud(i);
	m = n;
	for (int i = 1;i < m;i++){
		swap(a[1],a[n]);
		n--;
		ud(1);
		a[1] += a[n + 1];
		ans += a[1];
		ud(1);
	}
	printf("%lld",ans);
}