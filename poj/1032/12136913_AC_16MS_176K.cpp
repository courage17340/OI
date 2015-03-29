#include<cstdio>
int n,k,a[1010],p;
int main(){
	scanf("%d",&n);
	a[1]=2;
	n-=2;
	k=1;
	while (n>=k+2){
		k++;
		a[k]=k+1;
		n-=(k+1);
	}
	p=k;
	while (n--){
		a[p]++;
		p--;
		if (p==0) p=k;
	}
	for (int i=1;i<k;i++) printf("%d ",a[i]);
	printf("%d\n",a[k]);
}