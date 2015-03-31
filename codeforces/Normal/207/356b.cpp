#include<cstdio>
#include<cstring>
typedef long long ll;
ll n,m,l1,l2,a[27],b[27],ans,k,p,q,r=0;
char s[1000010],t[1000010];
ll gcd(ll a,ll b){
	if (b==0) return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	scanf("%s%s",s,t);
	l1=strlen(s);
	l2=strlen(t);
	ans=gcd(n,m);
	k=gcd(l1,l2);
	for (int i=1;i<=k;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		q=0;
		for (int j=i-1;j<l1;j+=k)
			a[s[j]-'a']++;
		for (int j=i-1;j<l2;j+=k){
			b[t[j]-'a']++;
			q++;
		}
		for (int j=0;j<26;j++) r+=a[j]*(q-b[j]);
	}
	ans*=r;
	printf("%I64d",ans);
}
