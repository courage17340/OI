#define ll long long
#include<cstdio>
int n,m;
ll l,r,mid,a[100010],b[100010];
ll max(ll a,ll b){
	return (a>b?a:b);
}
bool yes(ll x){
	int p=1;
	ll y;
	for (int i=1;i<=n;i++){
		y=a[i];
		if (y-b[p]>x) return 0;
		if (y<=b[p]) y+=x;else y=max(y,max(x-y+b[p]*2,((x-y+b[p])>>1)+y));
		while (p<=m && b[p]<=y) p++;
		if (p>m) return 1;
	}
	if (p<=m) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%I64d",&b[i]);
	l=0;
	r=b[m]+a[1]-2;
	while (l!=r){
		mid=(l+r)>>1;
		if (yes(mid)) r=mid;else l=mid+1;
	}
	printf("%I64d",l);
}
