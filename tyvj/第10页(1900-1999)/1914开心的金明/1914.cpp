#include<cstdio>
int f[30010]={0},n,m,x,y;
inline int max(int a,int b){
	return (a>b?a:b);
}
int main(){
	scanf("%d%d",&m,&n);
	while (n--){
		scanf("%d%d",&x,&y);
		for (int i=m;i>=x;i--) f[i]=max(f[i],f[i-x]+x*y);
	}
	printf("%d",f[m]);
}
