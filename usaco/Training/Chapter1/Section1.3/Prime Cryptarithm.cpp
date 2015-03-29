/*
ID: courage2
PROG: crypt1
LANG: C++
*/
#include <cstdio>
int n,x,a[10],ans = 0;
bool v[10] = {0};
bool yes(int x){
	while (x){
		if (!v[x % 10]) return 0;
		x /= 10;
	}
	return 1;
}
bool check(){
	int x = a[1] * 100 + a[2] * 10 + a[3],y = a[4] * 10 + a[5];
	if (x * a[5] < 100 || x * a[5] > 999 || !yes(x * a[5])) return 0;
	if (x * a[4] < 100 || x * a[4] > 999 || !yes(x * a[4])) return 0;
	if (x * y < 1000 || x * y > 9999 || !yes(x * y)) return 0;
	return 1;
}
void work(int x,int k){
	a[k] = x;
	if (k == 5){
		if (check()) ans++;
		return;
	}
	for (int i = 1;i <= 9;i++) if (v[i]) work(i,k + 1);
}
int main(){
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d",&x);
		v[x] = 1;
	}
	work(0,0);
	printf("%d\n",ans);
}
