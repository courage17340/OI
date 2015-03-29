#include <cstdio>
int x,y,z,n,m,a[10010];
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++) scanf("%d",a + i);
	x = a[1];
	y = 1;
	for (int i = 2;i <= m;i++) if (x == a[i]) y++;else{
		if (y == 1) x = a[i];else y--;
	}
	z = 0;
	for (int i = 1;i <= m;i++) if (a[i] == x) z++;
	if (z <= m / 2) printf("-1\n");else printf("%d\n",x);
}
