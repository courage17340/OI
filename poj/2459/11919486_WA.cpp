#include<cstdio>
struct rec{int x,y;};
rec a[2010];
int x,y,ans,p,n,d;
int main(){
	scanf("%d%d%d%d",&n,&x,&y,&d);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		if (a[i].y>d) a[i].y=d;
	}
	for (p=d;p>=1;p--){
		ans=0;
		for (int i=1;i<=n;i++) if (a[i].x<=p && p<=a[i].y) ans+=a[i].y-p+1;
			else if (p<a[i].x) ans+=a[i].y-a[i].x+1;
		if (ans>=x-y) break;
	}
	printf("%d\n",p);
}