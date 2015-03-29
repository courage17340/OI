#include<cstdio>
int f[10001],n,x,y,p,q,t;
int depth(int x){
	int s=0;
	while (x!=f[x]){
		x=f[x];
		s++;
	}
	return s;
}
int main(){
	scanf("%d",&t);
	for (int k=1;k<=t;k++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) f[i]=i;
		for (int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			f[y]=x;
		}
		scanf("%d%d",&x,&y);
		p=depth(x);
		q=depth(y);
		for (int i=1;i<=q-p;i++) y=f[y];
		for (int i=1;i<=p-q;i++) x=f[x];
		while (x!=y){
			x=f[x];
			y=f[y];
		}
		printf("%d\n",x);
	}
}