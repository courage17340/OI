#include<cstdio>
#include<cstring>
char s[110];
int a,b,c,l,flag;
int main(){
	scanf("%s",s);
	l=strlen(s);
	a=b=c=0;
	for (int i=0;i<l;i+=2){
		if (s[i]=='1') a++;
		if (s[i]=='2') b++;
		if (s[i]=='3') c++;
	}
	flag=0;
	if (a){
		a--;
		printf("1");
	}else
	if (b){
		b--;
		printf("2");
	}else{
		c--;
		printf("3");
	}
	for (int i=1;i<=a;i++) printf("+1");
	for (int i=1;i<=b;i++) printf("+2");
	for (int i=1;i<=c;i++) printf("+3");
}
