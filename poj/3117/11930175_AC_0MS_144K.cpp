#include<cstdio>
#include<cstring>
char s[20];
int n,t,ans,x;
int main(){
	while (scanf("%d%d",&t,&n)){
		if (t==0) break;
		ans=n*3;
		for (int i=1;i<=t;i++){
			scanf("%s%d",s,&x);
			ans-=x;
		}
		printf("%d\n",ans);
	}
}