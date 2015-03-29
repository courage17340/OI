/*
USER: courage2
LANG: C++
TASK: shuttle
*/
#include <cstdio>
int a[210],n,m = 0,k;
void work(int mid,int n,int k){
	int start,end;
	if (n & 1) start = mid - (n >> 1) * k * 2;else start = mid - (n - 1) * k;
	end = mid * 2 - start;
	for (int i = start;i != end;i += k * 2) a[++m] = i;
	a[++m] = end;
}
int main(){
	freopen("shuttle.in","r",stdin);
	freopen("shuttle.out","w",stdout);
	scanf("%d",&n);
	k = 1;
	for (int i = 2;i <= n + 1;i++){
		work(n + 1,i,k);
		k = -k;
	}
	for (int i = n;i >= 1;i--){
		work(n + 1,i,k);
		k = -k;
	}
	for (int i = 1;i <= m;i++){
		printf("%d",a[i]);
		if (i == m) break;
		if (i % 20 == 0) printf("\n");else printf(" ");
	}
	printf("\n");
}
