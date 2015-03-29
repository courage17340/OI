#include<cstdio>
struct point{int x,y;};
point a[700];
int n,x,y,m,ans,f[700];
inline bool cmp(point a,point b){
	return (a.x>=b.x && a.y>=b.y);
}
inline int max(int a,int b){
	return (a>b?a:b);
}
int main(){
	while (1){
		n=0;
		while (1){
			scanf("%d%d",&x,&y);
			if (x==-1) return 0;
			if (x==0) break;
			n++;
			a[n].x=x;
			a[n].y=y;
		}
		for (int i=1;i<=n;i++) f[i]=1;
		for (int i=2;i<=n;i++) for (int j=1;j<i;j++) if (!cmp(a[i],a[j])) f[i]=max(f[i],f[j]+1);
		ans=f[1];
		for (int i=1;i<=n;i++) ans=max(ans,f[i]);
		printf("%d\n",ans);
	}
}