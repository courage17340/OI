#include <cstdio>
int x,y,a[50010] = {0},b[50010] = {0},n,m;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d",&x,&y);
		a[x]++;
		a[y + 1]--;
	}
	x = 0;
	for (int i = 0;i <= 50000;i++){
		x += a[i];
		b[i] = x;
	}
	scanf("%d",&m);
	while (m--){
		scanf("%d",&x);
		printf("%d\n",b[x]);
	}
}
