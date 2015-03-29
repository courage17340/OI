#include<cstdio>
typedef long long ll;
int n,l,c,x,b[50010]={0},r,s;
ll f[50010]={0},p[50010]={0},q;
double k(int i,int j){
	return (1.0*p[j]*p[j]+f[j]-1.0*p[i]*p[i]-f[i])/(p[j]-p[i]);
}
int main(){
	scanf("%d%d",&n,&l);
	c=l+1;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		p[i]=p[i-1]+x+1;
	}
	r=s=0;
	for (int i=1;i<=n;i++){
		q=p[i]-c;
		while (r<s && k(b[r],b[r+1])<2*q) r++;
		f[i]=f[b[r]]+(q-p[b[r]])*(q-p[b[r]]);
		while (r<s && k(b[s],b[s-1])>k(i,b[s])) s--;
		b[++s]=i;
	}
	printf("%lld",f[n]);
}
