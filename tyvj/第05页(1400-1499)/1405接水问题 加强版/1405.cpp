#include <cstdio>
int a[200010],n,m,x;
void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}
void ud(int x){
	int k = x;
	if (x * 2 <= m && a[k] > a[x * 2]) k = x * 2;
	if (x * 2 + 1 <= m && a[k] > a[x * 2 + 1]) k = x * 2 + 1;
	if (k == x) return;
	swap(a[x],a[k]);
	ud(k);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++) scanf("%d",&a[i]);
	for (int i = n >> 1;i >= 1;i--) ud(i);
	for (int i = m + 1;i <= n;i++){
		scanf("%d",&x);
		a[1] += x;
		ud(1);
	}
	x = a[1];
	for (int i = 2;i <= m;i++) if (x < a[i]) x = a[i];
	printf("%d",x);
}
