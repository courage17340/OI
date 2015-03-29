#include<cstdio>
int n,ans,p,x,y;
int main(){
	scanf("%d",&n);
	p=1;
	ans=0;
	for (int i=1;i<=n;i++){
		x=0;
		for (int j=1;j<=n;j++){
			scanf("%d",&y);
			if (y==3) x++;
		}
		if (ans<x){
			ans=x;
			p=i;
		}
	}
	printf("%d",p);
}