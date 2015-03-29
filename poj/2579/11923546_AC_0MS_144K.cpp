#include<cstdio>
#include<cstring>
int a[15][15],r,c;
char s[20];
int main(){
	while (1){
		scanf("%s",s);
		if (s[3]=='O') break;
		scanf("%d%d",&r,&c);
		for (int i=1;i<=r;i++){
			scanf("%s",s);
			for (int j=1;j<=c;j++) a[i][j]=s[j-1]-48;
		}
		scanf("%s",s);
		for (int i=1;i<r;i++){
			for (int j=1;j<c;j++) printf("%d",(a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1])/4);
			printf("\n");
		}
	}
}