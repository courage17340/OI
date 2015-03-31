#include<cstdio>
#include<cstring>
const int md=1000000007;
int n,l,x,a[30]={0},p,q,y;
char s[100010];
int pow(int s,int x){
	memset(a,0,sizeof(a));
	int p=0;
	while (x){
		p++;
		a[p]=x&1;
		x>>=1;
	}
	int k=1;
	for (int i=p;i>=1;i--){
		k=(long long)k*k%md;
		if (a[i]) k=(long long)k*s%md;
	}
	return k;
}
int f(int x){
	if (x==1) return 1;
	int k=(long long)f(x>>1)*(pow(y,x>>1)+1)%md;
	if (x&1) k=((long long)k+pow(y,x-1))%md;
	return k;
}
int main(){
	scanf("%s%d",s,&n);
	l=strlen(s);
	x=0;
	for (int i=l-1;i>=0;i--) if (s[i]=='0'||s[i]=='5') x=((long long)x+pow(2,i))%md;
	y=pow(2,l);
	x=(long long)x*f(n)%md;
	printf("%d",x);
}
