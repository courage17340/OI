#include<cstdio>
#include<iostream>
#include<algorithm>
int n,m,k,f[200010],p=0;
struct rec{int x,y,w;};
rec a[200010];
long long ans=0;
bool yes=1;
bool cmp(rec a,rec b){
    return (a.w<b.w);
}
int father(int x){
    if (x==f[x]) return x;
    f[x]=father(f[x]);
    return f[x];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
    std::sort(a+1,a+m+1,cmp);
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<=m;i++)
        if (father(a[i].x)!=father(a[i].y)){
        	f[father(a[i].x)]=father(a[i].y);
            ans+=a[i].w;
        }
    for (int i=1;i<=n;i++) if (father(i)!=father(k)){
        p++;
        yes=0;
    }
    if (yes) std::cout<<ans;else printf("%d",p);
}
