#include<cstdio>
#include<cstring>
char s[24]="0123456789ABCDEFGHIJ";
int x,y,r,a[100],p;
int main(){
	while (scanf("%d%d",&x,&r)!=EOF){
		memset(a,0,sizeof(a));
		p=0;
		y=x;
		while (x){
			p++;
			a[p]=x%r;
			x/=r;
		}
		for (int i=1;i<=p;i++)
			if (a[i]<0) while (a[i]<0){
			a[i]-=r;
			a[i+1]++;
			if (a[i+1]!=0 && i==p) p++;
		} else if (a[i]>=-r) while (a[i]>=-r){
			a[i]+=r;
			a[i+1]--;
			if (a[i+1]!=0 && i==p) p++;
		}
		printf("%d=",y);
		for (int i=p;i>0;i--) printf("%c",s[a[i]]);
		printf("(base%d)\n",r);
	}
}
