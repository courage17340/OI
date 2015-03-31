#include<cstdio>
#include<cstring>
char s[100010];
int x[100010]={0},a[100010]={0},p,q,ans,n,m;
int main(){
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++) if(s[i]=='+') x[i+1]=1;
	p=0;
	for (int i=1;i<=n;i++){
		p++;
		a[p]=x[i];
		while (p>1 && a[p]==a[p-1]) p-=2;
	}
	while (p>1 && a[p]==a[p-1]) p-=2;
	if (p==0) printf("Yes");else printf("No");
}
