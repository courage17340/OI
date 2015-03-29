#include <cstdio>
#include <cstring>
int x,m,f[110],a[110],ans;
int d(int x){
	int ans = 0;
	while (x){
		ans += (x & 1);
		x >>= 1;
		ans++;
	}
	return ans;
}
void search(int k,int x,int y){
	if (k >= ans) return;
	if (x == y){
		if (k < ans) ans = k;
		return;
	}
	a[k] = x;
	for (int i = 1;i <= k;i++) if (a[i] + a[k] <= y) search(k + 1,a[i] + a[k],y);
}
int main(){
	for (int i = 1;i <= 100;i++){
		ans = d(i) - 1;
		search(1,1,i);
		f[i] = ans;
	}
	while (1){
		scanf("%d",&x);
		if (!x) break;
		printf("%d\n",f[x]);
	}
}
