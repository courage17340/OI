#include<cstdio>
int f[300010],a[300010],x,t,p,q,n,m,ans;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d",&ans);
	f[0]=0;
	f[1]=ans;
	for (int i=2;i<=n;i++){
		scanf("%d",&x);
		f[i]=x+f[i-1];
	}
	a[1]=0;
	p=q=1;
	for (int i=1;i<=n;i++){
		while (q>=p && f[i]<=f[a[q]]) q--;
		q++;
		a[q]=i;
		while (a[p]<i-m) p++;
		if (ans<f[i]-f[a[p]] && a[p]!=i) ans=f[i]-f[a[p]];
	}
	printf("%d",ans);
}
