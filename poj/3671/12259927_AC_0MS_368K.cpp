#include<cstdio>
int n,x,s1[30010]={0},s2[30010]={0},ans;
inline int min(int a,int b){
	return (a<b?a:b);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		s1[i]=s1[i-1];
		s2[i]=s2[i-1];
		if (x==1) s1[i]++;else s2[i]++;
	}
	ans=n;
	for (int i=0;i<=n;i++) ans=min(ans,s2[i]+s1[n]-s1[i]);
	printf("%d",ans);
}