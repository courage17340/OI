/*
ID: courage2
PROG: checker
LANG: C++
*/
#include <cstdio>
int n,a[20],ans = 0;
bool b[20] = {0},c[30] = {0},d[30] = {0};
void search(int k,int x){
	a[k] = x;
	b[x] = c[k + x] = d[k - x + n] = 1;
	if (k == n){
		ans++;
		if (ans <= 3){
			for (int i = 1;i < n;i++) printf("%d ",a[i]);
			printf("%d\n",a[n]);
		}
		b[x] = c[k + x] = d[k - x + n] = 0;
		return;
	}
	for (int i = 1;i <= n;i++) if (!b[i] && !c[k + 1 + i] && !d[k + 1 - i + n]) search(k + 1,i);
	b[x] = c[k + x] = d[k - x + n] = 0;
}
int main(){
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) search(1,i);
	printf("%d\n",ans);
}
