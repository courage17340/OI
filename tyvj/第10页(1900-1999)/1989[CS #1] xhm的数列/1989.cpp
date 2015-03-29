#include <cstdio>
typedef long long ll;
ll a[100010] = {0},b[100010] = {0},z;
int n,m,k,x,y;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	while (m--){
		scanf("%d%d%lld",&x,&y,&z);
		b[x] += z;
		b[y + 1] -= z;
	}
	z = 0;
	for (int i = 1;i <= n;i++){
		z += b[i];
		a[i] += z;
	}
	while (k--){
		scanf("%d",&x);
		printf("%lld\n",a[x]);
	}
}
