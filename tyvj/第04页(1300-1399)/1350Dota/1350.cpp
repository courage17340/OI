#include<cstdio>
#include<iostream>
#include<cstring>
#define ll long long
int a[300010],n,ans;
ll f[300010]={0};
inline ll min(ll a,ll b){
	return (a<b?a:b);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0]=f[1]=a[1];
	f[2]=a[2];
	for (int i=3;i<=n;i++){
		f[i]=f[i-1];
		if (i>2) f[i]=min(f[i],f[i-2]);
		if (i>3) f[i]=min(f[i],f[i-3]);
		f[i]+=a[i];
	}
	std::cout<<min(f[n-1],f[n]);
}
