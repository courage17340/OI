#include<cstdio>
int n,x;
int f(int x){
	if (x<=10) return x;
	if (x%10>=5) x+=10-x%10;else x-=x%10;
	return (f(x/10)*10);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		printf("%d\n",f(x));
	}
}