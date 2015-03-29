#include <cstdio>
int a[10010] = {0},b[10010],n,ans = 0;
void work(){
	for (int i = 2;i <= n;i++){
		b[i] = a[i - 1] - b[i - 1] - b[i - 2];
		if (b[i] < 0 || b[i] > 1) return;
	}
	if (a[n] != b[n] + b[n - 1]) return;
	ans++;
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	b[1] = 0;
	work();
	b[1] = 1;
	work();
	printf("%d\n",ans);
}
