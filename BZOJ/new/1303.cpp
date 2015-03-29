#include <cstdio>
int n,p,x,y,a[100010],b[200010] = {0},c[200010] = {0};
typedef long long ll;
ll ans = 0;
int main(){
	scanf("%d%d",&n,&x);
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if (x == a[i]) p = i;
	}
	b[100000] = c[100000] = 1;
	y = 100000;
	for (int i = p - 1;i >= 1;i--){
		if (a[i] > x) y++;else y--;
		b[y]++;
	}
	y = 100000;
	for (int i = p + 1;i <= n;i++){
		if (a[i] < x) y++;else y--;
		c[y]++;
	}
	for (int i = 0;i <= 200000;i++) ans += (ll)b[i] * c[i];
	printf("%lld",ans);
}
