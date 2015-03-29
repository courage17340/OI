#include<cstdio>
int f[50010]={0},p[20],v[20],n,m,k,q,s,x,y;
inline int max(int a,int b){
    return (a>b?a:b);
}
int main(){
    scanf("%d%d",&n,&m);
    while (n--){
        scanf("%d%d%d",&k,&x,&y);
        if (k==-1){
            for (int i=x;i<=m;i++) f[i]=max(f[i],f[i-x]+y);
            continue;
        }
        q=1;
        s=0;
        while (k){
            s++;
            k-=q;
            p[s]=x*q;
            v[s]=y*q;
            q*=2;
            if (q>k) q=k;
        }
        for (int i=1;i<=s;i++)
            for (int j=m;j>=p[i];j--) f[j]=max(f[j],f[j-p[i]]+v[i]);
    }
    printf("%d",f[m]);
}
