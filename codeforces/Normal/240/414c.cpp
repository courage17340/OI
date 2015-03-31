#include <cstdio>
typedef long long ll;
int n,m,a[2000010],b[2000010],c[2000010],k,x,p[110] = {0};
ll ans[100][2] = {{0}},bad[100] = {0},f[21],re;
void merge(int R,int k,int l,int r){
	if (l == r) return;
	int m = (l + r) >> 1;
	merge(R,k - 1,l,m);
	merge(R,k - 1,m + 1,r);
	ll t = 0;
	for (int i = l;i <= r;i++) b[i] = a[i];
	int p = l,q = m + 1,s = l - 1;
	while (p <= m && q <= r){
		if (b[p] <= b[q]){
			a[++s] = b[p++];
			if (b[p] == b[q]) bad[k]++;
		}
		else{
			t += (long long)(m - p + 1);
			a[++s] = b[q++];
		}
	}
	for (int i = p;i <= m;i++) a[++s] = b[i];
	for (int i = q;i <= r;i++) a[++s] = b[i];
	ans[k][R] += t;
	ll x = 0;
	for (int i = l;i < r;i++) if (a[i] == a[i + 1]) x++;
}
int main(){
	for (int i = 0;i < 21;i++) f[i] = (1 << i);
	scanf("%d",&m);
	n = (1 << m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++) c[i] = a[n + 1 - i];
	merge(0,m,1,n);
	for (int i = 1;i <= n;i++) a[i] = c[i];
	merge(1,m,1,n);
	scanf("%d",&k);
	while (k--){
		scanf("%d",&x);
		for (int i = 1;i <= x;i++) p[i] = !p[i];
		re = 0;
		for (int i = 1;i <= m;i++) re += ans[i][p[i]];
		printf("%I64d\n",re);
	}
}
