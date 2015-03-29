/*
USER: courage2
LANG: C++
TASK: fence9
*/
#include <cstdio>
int n,m,p,s;
int main(){
	freopen("fence9.in","r",stdin);
	freopen("fence9.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	s = m * p;
	s -= p;
	for (int y = 1;y < m;y++){
		if (n * y % m == 0) s--;
		if (y * (n - p) % m == 0) s--;
	}
	s >>= 1;
	printf("%d\n",s);
}
