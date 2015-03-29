#include <cstdio>
int n,a[20],b[20],x,k,ans;
void p(int a[],int x){
	a[x - 1] ^= 1;
	a[x] ^= 1;
	a[x + 1] ^= 1;
}
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++){
		scanf("%d",&x);
		a[i] ^= x;
		b[i] = a[i];
	}
	if (n == 1){
		printf("%d",a[1]);
		return 0;
	}
	p(a,1);
	x = 1;
	for (int i = 2;i <= n;i++) if (a[i - 1]){
		p(a,i);
		x++;
	}
	if (a[n] == 0) ans = x;else ans = -1;
	x = 0;
	for (int i = 2;i <= n;i++) if (b[i - 1]){
		p(b,i);
		x++;
	}
	if (b[n] == 0) if (ans == -1) ans = x;else ans = min(ans,x);
	if (ans >= 0) printf("%d",ans);else printf("Boring");
}
