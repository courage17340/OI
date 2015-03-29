/*
ID: courage2
PROG: sprime
LANG: C++
*/
#include <cstdio>
int n;
bool p(int x){
	for (int i = 2;i * i <= x;i++) if (x % i == 0) return 0;
	return 1;
}
void search(int x,int k){
	if (k == n){
		printf("%d\n",x);
		return;
	}
	x *= 10;
	for (int i = 1;i <= 9;i += 2) if (p(x + i)) search(x + i,k + 1);
}
int main(){
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	scanf("%d",&n);
	for (int i = 2;i <= 9;i++) if (p(i)) search(i,1);
}
