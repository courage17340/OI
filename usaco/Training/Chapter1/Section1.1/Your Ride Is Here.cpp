/*
ID: courage2
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <cstring>
char s[10];
int a = 1,b = 1;
int main(){
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	scanf("%s",s);
	for (int i = 0;i < strlen(s);i++) a = a * (s[i] - 64) % 47;
	scanf("%s",s);
	for (int i = 0;i < strlen(s);i++) b = b * (s[i] - 64) % 47;
	if (a == b) printf("GO\n");else printf("STAY\n");
}
