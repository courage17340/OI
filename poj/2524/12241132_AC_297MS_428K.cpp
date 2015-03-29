#include<cstdio>
#include<cstring>
int f[50010],n,m,x,y,ans,t=0;
bool a[50010];
int father(int x){
	if (x==f[x]) return x;
	int y=father(f[x]);
	f[x]=y;
	return y;
}
int main(){
	while (1){
		scanf("%d%d",&n,&m);
		t++;
		if (n==0) break;
		for (int i=1;i<=n;i++) f[i]=i;
		while (m--){
			scanf("%d%d",&x,&y);
			if (father(x)!=father(y)) f[father(x)]=father(y);
		}
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++) a[father(i)]=1;
		ans=0;
		for (int i=1;i<=n;i++) ans+=a[i];
		printf("Case %d: %d\n",t,ans);
	}
}