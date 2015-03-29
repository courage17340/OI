#include<cstdio>
#include<cstring>
char s[30];
int n,i,j;
int f(char c){
	if (c=='B' || c=='F' || c=='P' || c=='V') return 1;
	if (c=='C' || c=='G' || c=='J' || c=='K' || c=='Q' || c=='S' || c=='X' || c=='Z') return 2;
	if (c=='D' || c=='T') return 3;
	if (c=='L') return 4;
	if (c=='M' || c=='N') return 5;
	if (c=='R') return 6;
	return 0;
}
int main(){
	while (scanf("%s",s)!=EOF){
		n=strlen(s);
		i=j=0;
		while (i<n){
			while (j<n-1 && f(s[i])==f(s[j+1])) j++;
			if (f(s[i])) printf("%d",f(s[i]));
			i=j+1;
			j=i;
		}
		printf("\n");
	}
}