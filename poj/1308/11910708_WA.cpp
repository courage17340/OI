#include<cstdio>
#include<cstring>
int f[1010],n=0,x,y,z;
bool v[1010],p;
int father(int x){
	int y=x;
	while (y!=f[y]) y=f[y];
	f[x]=y;
	return y;
}
int main(){
	while (1){
		scanf("%d%d",&x,&y);
		if (x==-1) break;
		n++;
		if (x==0 && y==0){
			printf("Case %d is a tree.\n",n);
			continue;
		}
		for (int i=1;i<=1000;i++) f[i]=i;
		memset(v,0,sizeof(v));
		v[x]=v[y]=1;
		p=1;
		if (x==y) p=0;
		f[y]=x;
		while (scanf("%d%d",&x,&y)){
			if (x==0) break;
			if (father(x)==father(y) || father(x)!=father(y) && y!=f[y]) p=0;
			v[x]=v[y]=1;
		}
		for (int i=1;i<=1000;i++) if (v[i]){
			z=father(i);
			break;
		}
		for (int i=1;i<=1000;i++) if (v[i] && father(i)!=z) p=0;
		if (p) printf("Case %d is a tree.\n",n); else printf("Case %d is not a tree.\n",n);
	}
}