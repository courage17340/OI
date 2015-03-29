#include <cstdio>
typedef long long ll;
ll a[2000010];
int n,m,l[2010],r[2010],c[2010],x,y,z,p;
char s[3];
ll g(int k,int x,int y,int x0,int y0){
	ll ans = 0;
	if (y0 < x || y < x0) return 0;
	if (x < x0) x = x0;
	if (y > y0) y = y0;
	if (x > y) return 0;
	return (ll)(y - x + 1) * c[k];
}
ll f(int x,int y){
	ll ans = a[y] - a[x - 1];
	for (int i = 1;i <= p;i++) ans += g(i,x,y,l[i],r[i]);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	a[0] = 0;
	for (int i = 1;i <= n;i++){
		scanf("%d",&x);
		a[i] = a[i - 1] + x;
	}
	p = 0;
	while (m--){
		scanf("%s%d%d",s,&x,&y);
		if (s[0] == 'Q') printf("%lld\n",f(x + 1,y + 1));else{
			scanf("%d",&z);
			p++;
			l[p] = x + 1;
			r[p] = y + 1;
			c[p] = z;
		}
	}
}
