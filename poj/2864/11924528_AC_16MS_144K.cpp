#include<cstdio>
#include<cstring>
int a[110],n,d,x;
bool flag;
int main(){
	while (1){
		scanf("%d%d",&n,&d);
		if (n==0) break;
		flag=0;
		memset(a,0,sizeof(a));
		for (int i=1;i<=d;i++)
			for (int j=1;j<=n;j++){
				scanf("%d",&x);
				a[j]+=x;
			}
		for (int i=1;i<=n;i++) if (a[i]==d) flag=1;
		if (flag) printf("yes\n");else printf("no\n");
	}
}