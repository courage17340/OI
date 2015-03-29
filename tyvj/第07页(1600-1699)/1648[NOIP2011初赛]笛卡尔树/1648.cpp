#include <cstdio>
int n,a[110],ans,x;
void work(int d,int l,int r){
	if (l > r) return;
	if (l == r){
		if (d == x) ans++;
		if (d > x){
			x = d;
			ans = 1;
		}
		return;
	}
	int k = l;
	for (int i = l + 1;i <= r;i++) if (a[i] < a[k]) k = i;
	work(d + 1,l,k - 1);
	work(d + 1,k + 1,r);
}
int main(){
	x = 0;
	ans = 0;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	work(1,1,n);
	printf("%d %d\n",x,ans);
}
