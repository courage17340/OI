#include <cstdio>
int a[100010],n,x,l,r,m,p;
int find(int x){
	l = 1;
	r = p;
	while (l != r){
		m = (l + r) >> 1;
		if (a[m] < x) l = m + 1;else r = m;
	}
	return l;
}
int main(){
	scanf("%d",&n);
	p = 0;
	for (int i = 1;i <= n;i++){
		scanf("%d",&x);
		if (a[p] < x){
			a[++p] = x;
			continue;
		}
		a[find(x)] = x;
	}
	printf("%d\n",n - p);
}
