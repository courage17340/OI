#include <cstdio>
#include <algorithm>
int f[20010],rank[20010] = {0},n,m;
struct rec{int x,y,c;};
rec a[100010];
bool cmp(rec a,rec b){
	return a.c > b.c;
}
int father(int x){
	if (f[x] == x) return x;
	int y = father(f[x]);
	rank[x] ^= rank[f[x]];
	f[x] = y;
	return y;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
	std::sort(a + 1,a + m + 1,cmp);
	for (int i = 1;i <= m;i++){
		if (father(a[i].x) == father(a[i].y) && rank[a[i].x] == rank[a[i].y]){
			printf("%d\n",a[i].c);
			return 0;
		}
		if (father(a[i].x) != father(a[i].y)){
			int p = father(a[i].x);
			f[p] = father(a[i].y);
			rank[p] = rank[a[i].x] ^ rank[a[i].y] ^ 1;
		}
	}
	printf("0\n");
}
