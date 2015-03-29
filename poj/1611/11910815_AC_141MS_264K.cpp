#include<cstdio>
int f[30000],n,m,k,ans,p,x,y;
int father(int x){
	int y=x;
	while (y!=f[y]) y=f[y];
	f[x]=y;
	return y;
}
int main(){
	while (1){
		scanf("%d%d",&n,&m);
		if (n==0) break;
		for (int i=0;i<n;i++) f[i]=i;
		for (int i=1;i<=m;i++){
			scanf("%d",&k);
			if (k==0) continue;
			scanf("%d",&x);
			for (int j=2;j<=k;j++){
				scanf("%d",&y);
				if (father(x)!=father(y)) f[father(x)]=father(y);
			}
		}
		ans=1;
		p=father(0);
		for (int i=1;i<n;i++) if (father(i)==p) ans++;
		printf("%d\n",ans);
	}
}