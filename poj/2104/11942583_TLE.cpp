#include<cstdio>
#include<algorithm>
int n,m,x,y,k,a[100010],b[100010];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	while (m){
		m--;
		scanf("%d%d%d",&x,&y,&k);
		for (int i=x-1;i<y;i++) b[i]=a[i];
		std::nth_element(b+x-1,b+x+k-2,b+y);
		printf("%d\n",b[x+k-2]);
	}
}