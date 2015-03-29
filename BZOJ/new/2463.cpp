#include <cstdio>
int x;
char s[2][6] = {"Alice","Bob"};
int main(){
	while (1){
		scanf("%d",&x);
		if (x == 0) break;
		printf("%s\n",s[x & 1]);
	}
}
