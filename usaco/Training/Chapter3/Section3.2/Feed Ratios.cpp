/*
USER: courage2
LANG: C++
TASK: ratios
*/
#include <cstdio>
int x[4],y[4],z[4],a,b,c;
int main(){
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	for (int i = 0;i < 4;i++) scanf("%d%d%d",x + i,y + i,z + i);
	for (int k = 1;k < 300;k++)
		for (int i = 0;i < 100 && i <= k;i++)
			for (int j = 0;j < 100 && i + j <= k;j++){
				int l = k - i - j;
				if (l >= 100) continue;
				a = i * x[1] + j * x[2] + l * x[3];
				b = i * y[1] + j * y[2] + l * y[3];
				c = i * z[1] + j * z[2] + l * z[3];
				int t = a / x[0];
				if (t * x[0] == a && t * y[0] == b && t * z[0] == c){
					printf("%d %d %d %d\n",i,j,l,t);
					return 0;
				}
			}
	puts("NONE");
}
