#include <cstdio>
#include <cstring>
int f[26] = {0},l,k;
char s[100];
int main(){
	while (scanf("%s",s) != EOF){
		l = strlen(s);
		for (int i = 0;i < l;i++) if ('A' <= s[i] && s[i] <= 'Z') f[s[i] - 'A']++;
	}
	k = 0;
	for (int i = 0;i < 26;i++) if (k < f[i]) k = f[i];
	for (int i = k;i >= 1;i--){
		for (int j = 0;j < 25;j++) if (f[j] >= i) printf("* ");else printf("  ");
		if (f[25] >= i) printf("*\n");else printf(" \n");
	}
	for (int i = 0;i < 25;i++) printf("%c ",i + 'A');
	printf("Z\n");
}