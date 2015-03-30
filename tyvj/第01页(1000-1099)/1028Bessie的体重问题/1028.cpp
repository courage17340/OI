#include <cstdio>
int n,m,x;
bool f[45010] = {0};
int main(){
	f[0] = 1;
	scanf("%d%d",&m,&n);
	while (n--){
		scanf("%d",&x);
		for (int i = m;i >= x;i--) f[i] |= f[i - x];
	}
	x = m;
	while (x > 0 && !f[x]) x--;
	printf("%d\n",x);
}
