#include<cstdio>
#include<cstring>
char s[100];
bool f(){
	int n=strlen(s);
	for (int i=1;i<=n-2;i++)
		for (int j=0;j<n-i;j++)
			for (int k=j+1;k<=n-i;k++)
				if (s[j]==s[k] && s[j+i]==s[k+i]) return 0;
	return 1;
}
int main(){
	while (1){
		scanf("%s",s);
		if (s[0]=='*') break;
		if (f()) printf("%s is surprising.\n",s);else printf("%s is NOT surprising.\n",s);
	}
}