/*
USER: courage2
LANG: C++
TASK: heritage
*/
#include <cstdio>
#include <cstring>
char s[30],t[30];
int n;
void work(char *s,int l1,int r1,char *t,int l2,int r2){
	for (int i = l1;i <= r1;i++) if (s[i] == t[l2]){
		if (i > l1) work(s,l1,i - 1,t,l2 + 1,l2 + i - l1);
		if (i < r1) work(s,i + 1,r1,t,l2 + i - l1 + 1,r2);
		printf("%c",t[l2]);
		break;
	}
}
int main(){
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	scanf("%s%s",s,t);
	n = strlen(s);
	work(s,0,n - 1,t,0,n - 1);
	printf("\n");
}
