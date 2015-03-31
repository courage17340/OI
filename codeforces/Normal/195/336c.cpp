#include<cstdio>
int a[100010],n,x,y,p,r,q,k,f[32][2]={0};
int g(int x){
	int y=0;
	if (x==0) return 0;
	while ((x&1)==0){
		x>>=1;
		y++;
	}
	return y;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	x=a[n-1];
	y=0;
	while (x){
		x/=2;
		y++;
	}
	r=y;
	while (y>0){
		for (p=0;p<n;p++) if ((a[p]>>(y-1))&1) break;
		if ((a[p]>>(y-1))&1==0){
			y--;
			continue;
		}
		k=a[p];
		x=1;
		q=p;
		for (int i=p+1;i<n;i++) if ((a[i]>>(y-1))&1){
			k&=a[i];
			x++;
		}
		f[y][0]=g(k);
		f[y][1]=x;
		y--;
	}
	f[0][0]=0;
	f[0][1]=n;
	x=0;
	for (int i=1;i<=r;i++) if (f[i][0]>f[x][0] || f[i][0]==f[x][0] && f[i][1]>f[x][1]) x=i;
	printf("%d\n",f[x][1]);
	if (x==0){
		for (int i=0;i<n-1;i++) printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
		return 0;
	}
	k=0;
	for (int i=0;i<n;i++) if ((a[i]>>(x-1))&1){
		k++;
		printf("%d",a[i]);
		if (k==f[x][1]) printf("\n");else printf(" ");
	}
}
