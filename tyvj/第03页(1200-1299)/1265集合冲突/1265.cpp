#include <cstdio>
#include <algorithm>
typedef long long ll;
ll a[100010],b[100010];
int n,m,same,p;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	scanf("%d",&m);
	for (int i = 1;i <= m;i++) scanf("%lld",&b[i]);
	std::sort(a + 1,a + n + 1);
	std::sort(b + 1,b + m + 1);
	b[0] = a[1] - 1;
	if (b[0] >= b[1]) b[0] = b[1] - 1;
	b[m + 1] = a[n] + 1;
	if (b[m + 1] <= b[m]) b[m + 1] = b[m] + 1;
	same = 0;
	p = 0;
	for (int i = 1;i <= n;i++){
		while (b[p] < a[i]) p++;
		if (a[i] == b[p]) same++;
	}
	if (same == 0){
		printf("%s","A and B are disjoint");
		return 0;
	}
	if (n == m)
		if (same == n) printf("A equals B");
		else printf("I'm confused!");
	else if (n > m)
		if (same == m) printf("B is a proper subset of A");
		else printf("I'm confused!");
	else
		if (same == n) printf("A is a proper subset of B");
		else printf("I'm confused!");
}
