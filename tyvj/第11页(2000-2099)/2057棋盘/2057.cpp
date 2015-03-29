#include <cstdio>
int x;
char s[2][10] = {"Alice","Bob"};
int main(){
	while (scanf("%d",&x) != EOF) printf("%s\n",s[x & 1]);
}
