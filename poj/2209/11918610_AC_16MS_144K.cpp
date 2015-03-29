#include<cstdio>
int n,k,x,s=0;
int f(int x,int y){
	int p=1;
	for (int i=1;i<=y;i++) p*=x;
	return p;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (f(x,k)>0) s+=f(x,k);
	}
	printf("%d\n",s);
}