#include<cstdio>
#include<cstring>
char s[100],c;
bool b;
int i,j,k;
int main(){
	while (1){
		scanf("%s",s);
		if (strcmp(s,"#")==0) break;
		b=1;
		for (i=0;i<strlen(s)-1;i++) if (s[i]<s[i+1]) b=0;
		if (b){
			printf("No Successor\n");
			continue;
		}
		i=strlen(s)-2;
		while (s[i]>=s[i+1]) i--;
		j=strlen(s)-1;
		while (s[j]<=s[i]) j--;
		c=s[i];
		s[i]=s[j];
		s[j]=c;
		i++;
		j=strlen(s)-1;
		while (i<j){
			c=s[i];
			s[i]=s[j];
			s[j]=c;
			i++;
			j--;
		}
		printf("%s\n",s);
	}
}