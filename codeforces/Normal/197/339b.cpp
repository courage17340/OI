#include<iostream>
#include<cstdio>
long long ans=0;
int n,m,x,p;
int main(){
	scanf("%d%d",&n,&m);
	p=1;
	for (int i=1;i<=m;i++){
		scanf("%d",&x);
		if (p<=x) ans+=(x-p);else ans+=(n+x-p);
		p=x;
	}
	std::cout<<ans;
}
