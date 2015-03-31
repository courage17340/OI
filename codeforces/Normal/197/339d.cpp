#include<cstdio>
int n,m,tot,a[200010],f[300010],p,x;
void build(int k,int step,int l,int r){
	if (l==r){
		f[k]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(k*2,step+1,l,m);
	build(k*2+1,step+1,m+1,r);
	if ((n-step)&1) f[k]=f[k*2]|f[k*2+1];else f[k]=f[k*2]^f[k*2+1];
}
void change(int p,int x){
	int l=1,r=tot,m,step=n,k=1;
	while (l!=r){
		m=(l+r)>>1;
		if (p<=m){
			k<<=1;
			r=m;
		}else{
			k=k*2+1;
			l=m+1;
		}
	}
	f[k]=x;
	for (int i=step-1;i>=1;i--){
		k>>=1;
		if ((n-i)&1) f[k]=f[k*2]|f[k*2+1];else f[k]=f[k*2]^f[k*2+1];
	}
	printf("%d\n",f[1]);
}
int main(){
	scanf("%d%d",&n,&m);
	tot=1<<n;
	n++;
	for (int i=1;i<=tot;i++) scanf("%d",&a[i]);
	build(1,1,1,tot);
	while (m--){
		scanf("%d%d",&p,&x);
		change(p,x);
	}
}
