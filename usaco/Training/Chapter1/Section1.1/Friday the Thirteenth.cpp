/*
ID: courage2
PROG: friday
LANG: C++
*/
#include<cstdio>
int a[7] = {0},b[12] = {31,28,31,30,31,30,31,31,30,31,30,31},n,k;
int f(int i,int j){
	if (j != 2) return b[j - 1];
	i += 1899;
	if (i % 400 == 0 || (i % 4 == 0 && i % 100)) return 29;
	return 28;
}
int main(){
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	scanf("%d",&n);
	k = 6;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= 12;j++){
			a[k]++;
			k = (k + f(i,j)) % 7;
		}
	printf("%d",a[6]);
	for (int i = 0;i <= 5;i++) printf(" %d",a[i]);
	printf("\n");
}
