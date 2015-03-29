#include<cstdio>
#include<algorithm>
int f[2010],ans=0,n,m,k,x,y,w,p=0;
struct rec{int x,y,w;};
rec a[10010];
int father(int x){
    if (x==f[x]) return x;
    f[x]=father(f[x]);
    return f[x];
}
bool cmp(rec a,rec b){
    return (a.w<b.w);
}
int main(){
	scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) f[i]=i;
    while (m--){
        scanf("%d%d%d%d",&k,&x,&y,&w);
        if (k==1){
            ans+=w;
            if (father(x)!=father(y)) f[father(x)]=father(y);
            continue;
        }
        p++;
        a[p].x=x;
        a[p].y=y;
        a[p].w=w;
    }
    std::sort(a+1,a+p+1,cmp);
    for (int i=1;i<=p;i++)
        if (father(a[i].x)!=father(a[i].y)){
        	f[father(a[i].x)]=father(a[i].y);
        	ans+=a[i].w;
    	}
    printf("%d",ans);
}
