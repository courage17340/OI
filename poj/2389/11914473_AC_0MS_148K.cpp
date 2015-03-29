#include<cstdio>
#include<cstring>
const int l=100;
char s[l];
int a[l+1]={0},b[l+1]={0},c[l+1]={0},k,p,l1,l2;
int main(){
	scanf("%s",s);
	l1=strlen(s);
	for (int i=0;i<l1;i++) a[i+1-l1+l]=s[i]-48;
	scanf("%s",s);
	l2=strlen(s);
	for (int i=0;i<l2;i++) b[i+1-l2+l]=s[i]-48;
	for (int i=l+1-l1;i<=l;i++)
		for (int j=l+1-l2;j<=l;j++)
			c[i+j-l]+=a[i]*b[j];
	k=0;
	for (int i=l;i>0;i--){
		c[i]+=k;
		k=c[i]/10;
		c[i]%=10;
	}
	p=1;
	while (c[p]==0 && p<l) p++;
	for (int i=p;i<=l;i++) printf("%d",c[i]);
	printf("\n");
}