#include <cstdio>
#include <cstring>
int l1,l2,l,te;
bool f[410][210];
char s[210],t[210],u[410];
int main(){
	scanf("%d",&te);
	for (int T = 1;T <= te;T++){
		scanf("%s%s%s",s,t,u);
		memset(f,0,sizeof f);
		f[0][0] = 1;
		l1 = strlen(s);
		l2 = strlen(t);
		l = l1 + l2;
		for (int i = 1;i <= l;i++)
			for (int j = 0;j <= i && j <= l1;j++)
				f[i][j] = (f[i - 1][j] && i > j && u[i - 1] == t[i - j - 1]) || (j && f[i - 1][j - 1] && u[i - 1] == s[j - 1]);
		printf("Data set %d: %s\n",T,f[l][l1] ? "yes" : "no");
	}
}