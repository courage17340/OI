/*
ID: courage2
PROG: subset
LANG: C++
*/
#include <cstdio>
int n,m;
long long f[400] = {0};
int main(){
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	scanf("%d",&n);
	m = (n + 1) * n / 2;
	if (m & 1){
		printf("0\n");
		return 0;
	}
	m >>= 1;
	f[0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = m;j >= i;j--) f[j] += f[j - i];
	printf("%lld\n",f[m] >> 1);
}
