#include <cstdio>
int n,k,x,f[100010] = {0};
int max(int a,int b){return a > b ? a : b;}
int main(){
	scanf("%d%d",&n,&k);
	if (n / 2 > k || (n == 1 && k)){
		printf("-1\n");
		return 0;
	}
	x = k - n / 2 + 1;
	f[1] = x;
	f[2] = x * 2;
	int p = 1;
	for (int i = 3;i <= n;i += 2){
		while (p == x || p == x * 2 || p + 1 == x || p + 1 == x * 2) p++;
		f[i] = p;
		f[i + 1] = p + 1;
		p += 2;
	}
	if (!f[n]) f[n] = max(x * 2 + 1,p + 1);
	for (int i = 1;i < n;i++) printf("%d ",f[i]);
	printf("%d\n",f[n]);
}
