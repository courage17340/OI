#include<cstdio>
#include<cstring>
int n,m,k,p,r,x;
bool a[10000],flag;
char s[10];
int main(){
	while (1){
		scanf("%d",&n);
		if (n==0) break;
		scanf("%d",&m);
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			x=0;
			for (int j=0;j<4;j++) x=x*10+s[j]-48;
			a[x]=1;
		}
		flag=1;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&k,&p);
			r=0;
			for (int j=1;j<=k;j++){
				scanf("%s",s);
				x=0;
				for (int q=0;q<4;q++) x=x*10+s[q]-48;
				r+=a[x];
			}
			if (r<p) flag=0;
		}
		if (flag) printf("yes\n");else printf("no\n");
	}
}