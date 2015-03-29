/*
ID: courage2
TASK: lamps
LANG: C++
*/
#include <cstdio>
int a[110],n,c,b[110],p,x,f[8][6] = {{0},{0,0,1,1,1},{0,1,0,1,0,1},{0,1,1,0,1,1},{1,0,0,1},{1,0,1,0,1},{1,1,0,0,0,1},{1,1,1,1,1,1}};
bool flag = 0;
void work(int k){
	for (int i = 1;i <= n;i++) a[i] = f[k][(i - 1) % 6];
	for (int i = 1;i <= n;i++) if (b[i] >= 0 && a[i] != b[i]) return;
	flag = 1;
	for (int i = 1;i <= n;i++) printf("%d",a[i]);
	printf("\n");
}
int main(){
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	scanf("%d%d",&n,&c);
	for (int i = 1;i <= n;i++) b[i] = -1;
	while (1){
		scanf("%d",&x);
		if (x == -1) break;
		b[x] = 1;
	}
	while (1){
		scanf("%d",&x);
		if (x == -1) break;
		b[x] = 0;
	}
	if (c == 0){
		work(7);
	}else if (c == 1){
		work(0);
		work(2);
		work(3);
		work(5);
	}else if (c == 2) for (int i = 0;i < 8;i++) if (i != 3) work(i);
	if (c >= 3) for (int i = 0;i < 8;i++) work(i);
	if (!flag) printf("IMPOSSIBLE\n");
}
