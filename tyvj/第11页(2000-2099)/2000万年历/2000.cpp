#include <cstdio>
#include <cstring>
char s[10010];
int t,n,x,l,f[420];
bool p(int x){
	return x % 400 == 0 || (x % 100 && x % 4 == 0);
}
int main(){
	f[0] = 6;
	x = 1;
	for (int i = 1;i <= 410;i++){
		f[i] = x;
		x += 365 + p(i);
		x %= 7;
	}
	scanf("%d",&t);
	while (t--){
		scanf("%s",s);
		x = 0;
		l = strlen(s);
		for (int i = 0;i < l;i++) x = (x * 10 + s[i] - '0') % 400;
		printf("%d\n",f[x]);
	}
}
