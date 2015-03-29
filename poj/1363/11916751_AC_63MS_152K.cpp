#include<cstdio>
int a[1001],b[1001],n,k,p,i,j;
bool flag;
int main(){
	while (1){
		scanf("%d",&n);
		if (n==0) break;
		while (1){
			scanf("%d",&b[1]);
			if (b[1]==0) break;
			flag=1;
			for (i=2;i<=n;i++) scanf("%d",&b[i]);
			for (i=1;i<=b[1];i++) a[i]=i;
			k=b[1];
			i=b[1]-1;
			j=2;
			while (j<=n){
				while (k<b[j]){
					k++;
					i++;
					a[i]=k;
				}
				if (a[i]==b[j]){
					i--;
					j++;
				}else{
					flag=0;
					break;
				}
			}
			if (flag) printf("Yes\n");else printf("No\n");
		}
		printf("\n");
	}
}