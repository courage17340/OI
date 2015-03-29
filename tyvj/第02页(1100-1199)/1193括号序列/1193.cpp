#include <cstdio>
#include <cstring>
int l,f[300][300];
char s[300];
bool p(char a,char b){
	if (a == '(' && b == ')') return 1;
	return (a == '[' && b == ']');
}
int g(int i,int j){
	if (i > j) return 0;
	return f[i][j];
}
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	scanf("%s",s);
	l = strlen(s);
	memset(f,1,sizeof(f));
	for (int i = 0;i < l;i++) f[i][i] = 1;
	for (int k = 1;k < l;k++)
		for (int i = 0;i + k < l;i++){
			int j = i + k;
			if (p(s[i],s[j])) f[i][j] = min(f[i][j],g(i + 1,j - 1));
			for (int r = i;r < j;r++) f[i][j] = min(f[i][j],g(i,r) + g(r + 1,j));
		}
	printf("%d",f[0][l - 1]);
}
