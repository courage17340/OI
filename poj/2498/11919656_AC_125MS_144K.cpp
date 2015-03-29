#include<cstdio>
#include<cstring>
char s[10];
int b[10]={9,7,3,9,7,3,9},n,x,p,q;
int main(){
	scanf("%d",&n);
	for (int k=1;k<=n;k++){
		scanf("%s",s);
		q=strlen(s);
		x=0;
		for (int i=0;i<q;i++) if (s[i]=='?'){
			p=i;
			break;
		}
		for (int i=0;i<q;i++) if (i!=p) x+=(s[i]-48)*b[i+7-q];
		for (int i=0;i<=9;i++)
			if ((x+i*b[p+7-q])%10==0){
				s[p]=i+48;
				printf("Scenario #%d:\n%s\n\n",k,s);
				break;
			}
	}
}