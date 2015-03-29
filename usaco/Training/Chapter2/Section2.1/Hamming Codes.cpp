/*
ID: courage2
PROG: hamming
LANG: C++
*/
#include <cstdio>
inline int dis(int a,int b){
	a ^= b;
	int c = 0;
	while (a){
		c += (a & 1);
		a >>= 1;
	}
	return c;
}
int n,b,d,a[100],f[260][260];
bool flag = 0;
void out(){
	for (int i = 1;i <= n;i++){
		printf("%d",a[i]);
		if (i % 10 == 0 || i == n) printf("\n");else printf(" ");
	}
}
void search(int k,int x){
	if (flag) return;
	a[k] = x;
	for (int i = 1;i < k;i++) if (f[a[i]][x] < d) return;
	if (k == n){
		flag = 1;
		out();
		return;
	}
	for (int i = 0;i < (1 << b);i++) search(k + 1,i);
}
int main(){
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	scanf("%d%d%d",&n,&b,&d);
	for (int i = 0;i <= 256;i++)
		for (int j = 0;j <= 256;j++) f[i][j] = dis(i,j);
	search(0,0);
}
