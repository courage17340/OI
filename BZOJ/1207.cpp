#include<cstdio>
int n,m,t[10010],x[10010],y[10010],f[10010]={0},ans=1,p=0;
inline int max(int a,int b){
	return (a>b?a:b);
}
inline int abs(int x){
	return (x>0?x:-x);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		p++;
		scanf("%d%d%d",&t[p],&x[p],&y[p]);
		if (x[p]<1 || x[p]>n || y[p]<1 || y[p]>n) p--;
	}
	m=p;
	for (int i=1;i<=m;i++){
		f[i]=1;
		for (int j=1;j<i;j++) if (abs(x[i]-x[j])+abs(y[i]-y[j])<=abs(t[i]-t[j])) f[i]=max(f[i],f[j]+1);
	}
	for (int i=1;i<=m;i++) ans=max(ans,f[i]);
	printf("%d",ans);
}
