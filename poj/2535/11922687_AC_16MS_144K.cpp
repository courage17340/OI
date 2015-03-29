#include<cstdio>
int a[110],f[110]={0},n,p,k;
bool t;
int main(){
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=p;j++) scanf("%d",&a[j]);
		k=a[1];
		for (int j=2;j<=p;j++) if (k>a[j]) k=a[j];
		for (int j=1;j<=p;j++) if (k==a[j] && f[j]!=-1) f[j]++;
		k=a[1];
		for (int j=2;j<=p;j++) if (k<a[j]) k=a[j];
		for (int j=1;j<=p;j++) if (k==a[j]) f[j]=-1;
	}
	t=0;
	for (int i=1;i<=p;i++) if (f[i]>=(n/2+1)){
		if (t) printf(" ");
		printf("%d",i);
		t=1;
	}
	if (!t) printf("0");
	printf("\n");
}