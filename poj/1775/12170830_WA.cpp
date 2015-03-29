#include<cstdio>
bool f[1000010]={0};
int n,x,p,q;
int main(){
	f[0]=1;
	x=1;
	for (int i=1;i*x<=1000000;i++){
		x*=i;
		for (int j=1000000;j>=x;j--) f[j]|=f[j-x];
	}
	while (1){
		scanf("%d",&x);
		if (x<0) break;
		printf(f[x]?"YES\n":"NO\n");
	}
}