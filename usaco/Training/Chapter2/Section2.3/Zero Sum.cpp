/*
ID: courage2
TASK: zerosum
LANG: C++
*/
#include <cstdio>
char s[4] = " +-";
int a[10],n;
int sum(){
	int ans = 0,p = 1,q,x;
	while (p <= n){
		q = p;
		while (q < n && a[q + 1] == 0) q++;
		x = 0;
		for (int i = p;i <= q;i++) x = x * 10 + i;
		if (a[p] == 1) ans += x;else ans -= x;
		p = q + 1;
	}
	return ans;
}
void work(int k,int x){
	a[k] = x;
	if (k == n){
		if (sum() == 0){
			printf("1");
			for (int i = 2;i <= n;i++) printf("%c%d",s[a[i]],i);
			printf("\n");
		}
		return;
	}
	for (int i = 0;i <= 2;i++) work(k + 1,i);
}
int main(){
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	scanf("%d",&n);
	work(1,1);
}
