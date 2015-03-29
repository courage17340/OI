/*
USER: courage2
LANG: C++
TASK: kimbits
*/
#include <cstdio>
#include <cstring>
int a[40],n,l,C[33][33] = {{0}},x,y,z;
unsigned int m;
int main(){
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	scanf("%d%d%u",&n,&l,&m);
	for (int i = 0;i <= 31;i++) C[i][0] = 1;
	for (int i = 1;i <= 31;i++)
		for (int j = 1;j <= i;j++) C[i][j] = (i - 1 >= j ? C[i - 1][j] : 0) + (j ? C[i - 1][j - 1] : 0);
	for (int i = 1;i <= n;i++){
		x = 0;
		for (int j = 0;j <= l && j <= n - i;j++) x += C[n - i][j];
		if (m > x){
			m -= x;
			a[i] = 1;
			l--;
		}else{
			a[i] = 0;
		}
	}
	for (int i = 1;i <= n;i++) printf("%d",a[i]);
	printf("\n");
}
