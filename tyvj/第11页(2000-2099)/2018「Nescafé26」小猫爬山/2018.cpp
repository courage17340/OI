#include <cstdio>
int a[20],b[20] = {0},n,w,ans;
void search(int k,int p,int tot){
	if (tot >= ans) return;
	b[p] += a[k];
	if (k == n){
		if (ans > tot) ans = tot;
		b[p] -= a[k];
		return;
	}
	for (int i = 1;i <= tot;i++) if (b[i] + a[k + 1] <= w) search(k + 1,i,tot);
	search(k + 1,tot + 1,tot + 1);
	b[p] -= a[k];
}
int main(){
	scanf("%d%d",&n,&w);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	ans = n;
	search(1,1,1);
	printf("%d\n",ans);
}
