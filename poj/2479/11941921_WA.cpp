#include<cstdio>
#include<cstring>
int a[50010],f[50010],ans,t,n,x,k;
int main(){
	scanf("%d",&t);
	while (t){
		t--;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++) if (f[i-1]+a[i]<0) f[i]=0;else f[i]=f[i-1]+a[i];
		for (int i=2;i<=n;i++) if (f[i]<f[i-1]) f[i]=f[i-1];
		x=0;
		ans=a[1]+a[2];
		for (int i=n;i>=1;i--){
			if (x+a[i]<0) x=0;else x=x+a[i];
			if (x+f[i-1]>ans) ans=x+f[i-1];
		}
		printf("%d\n",ans);
	}
}