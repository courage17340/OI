#include <cstdio>
#include <cstring>
int f[10] = {0},l,a[1000010] = {0},p = 0,x,y;
char s[1000010];
int g(int x){
	if (x == 0) return 1869;
	if (x == 1) return 1896;
	if (x == 2) return 1986;
	if (x == 3) return 1698;
	if (x == 4) return 6198;
	if (x == 5) return 1689;
	return 1968;
}
int main(){
	scanf("%s",s);
	l = strlen(s);
	for (int i = 0;i < l;i++) f[s[i] - '0']++;
	f[1]--;
	f[6]--;
	f[8]--;
	f[9]--;
	for (int i = 1;i <= 9;i++) for (int j = 1;j <= f[i];j++) a[++p] = i;
	if (p == 0){
		printf("1869");
		for (int i = 1;i <= l - 4;i++) printf("0");
		printf("\n");
		return 0;
	}
	x = 0;
	for (int i = 1;i <= l - 4;i++) x = (x * 10 + a[i]) % 7;
	x = x * 10000 % 7;
	for (int i = 1;i <= l - 4;i++) printf("%d",a[i]);
	printf("%d\n",g(x));
}
