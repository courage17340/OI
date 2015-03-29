/*
ID: courage2
LANG: C++
PROG: namenum
*/
#include <cstdio>
#include <cstring>
bool flag = 0,k;
char s[20],t[20];
bool yes(char c,char d){
	if (c == '2' && 'A' <= d && d <= 'C') return 1;
	if (c == '3' && 'D' <= d && d <= 'F') return 1;
	if (c == '4' && 'G' <= d && d <= 'I') return 1;
	if (c == '5' && 'J' <= d && d <= 'L') return 1;
	if (c == '6' && 'M' <= d && d <= 'O') return 1;
	if (c == '7' && 'P' <= d && d <= 'S') return 1;
	if (c == '8' && 'T' <= d && d <= 'V') return 1;
	if (c == '9' && 'W' <= d && d <= 'Y') return 1;
	return 0;
}
int main(){
	freopen("namenum.in","r",stdin);
	scanf("%s",s);
	freopen("dict.txt","r",stdin);
	freopen("namenum.out","w",stdout);
	int l = strlen(s);
	while (scanf("%s",t) != EOF){
		if (strlen(t) != l) continue;
		k = 1;
		for (int i = 0;i < l;i++) if (!yes(s[i],t[i])) k = 0;
		if (!k) continue;
		printf("%s\n",t);
		flag = 1;
	}
	if (!flag) printf("NONE\n");
}
