#include <cstdio>
const int md = 1000000007;
int a[1010],f[1010] = {0},ans = 0,x,p,n;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	f[1] = 2;
	for (int i = 2;i <= n;i++){
		x = 2;
		p = a[i];
		while (p != i){
			x = (x + f[p]) % md;
			p++;
		}
		f[p] = x;
	}
	for (int i = 1;i <= n;i++) ans = (ans + f[i]) % md;
	printf("%d\n",ans);
}
