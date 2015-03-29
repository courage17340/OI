#include <cstdio>
char s[10];
int x = 0,ans,k,c[4][4] = {{0xF888,0xF444,0xF222,0xF111},{0x8F88,0x4F44,0x2F22,0x1F11},
	{0x88F8,0x44F4,0x22F2,0x11F1},{0x888F,0x444F,0x222F,0x111F}};
int f(int x){
	int y = 0;
	while (x){
		y += (x & 1);
		x >>= 1;
	}
	return y;
}
void work(int a){
	if (f(a) >= ans) return;
	int y = x,b = a,p,q;
	p = q = 4;
	while (p){
		if (a & 1) y ^= c[p - 1][q - 1];
		a >>= 1;
		q--;
		if (!q){
			p--;
			q = 4;
		}
	}
	if (y) return;
	ans = f(b);
	k = b;
}
int main(){
	for (int i = 0;i < 4;i++){
		scanf("%s",s);
		for (int j = 0;j < 4;j++) x = x * 2 + (s[j] == '+');
	}
	ans = 100;
	for (int i = 0;i < (1 << 16);i++) work(i);
	printf("%d\n",ans);
	int i = 4,j = 4;
	while (i){
		if (k & 1) printf("%d %d\n",i,j);
		k >>= 1;
		j--;
		if (!j){
			i--;
			j = 4;
		}
	}
}