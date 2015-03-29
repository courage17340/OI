#include<cstdio>
#include<cstring>
int a[20]={0},f[100010],n;
inline int min(int a,int b){
	return (a<b?a:b);
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<=n;i++) f[i]=i;
	for (int i=1;i<=17;i++) a[i]=i*i*i*i;
	for (int i=1;i<=17 && a[i]<=n;i++)
		for (int j=a[i];j<=n;j++) f[j]=min(f[j],f[j-a[i]]+1);
	printf("%d",f[n]);
}
