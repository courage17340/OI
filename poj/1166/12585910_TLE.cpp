#include<cstdio>
#include<cstring>
struct rec{int v[10];};
rec a;
int b[10][10]={{0},{0,1,1,0,1,1,0,0,0,0},{0,1,1,1,0,0,0,0,0,0},{0,0,1,1,0,1,1,0,0,0},
				{0,1,0,0,1,0,0,1,0,0},{0,0,1,0,1,1,1,0,1,0},{0,0,0,1,0,0,1,0,0,1},
				{0,0,0,0,1,1,0,1,1,0},{0,0,0,0,0,0,0,1,1,1},{0,0,0,0,0,1,1,0,1,1}};
int ans,f[100],g[100];
int sum(rec &a){
	int x = 0;
	for (int i = 1;i <= 9;i++) x += a.v[i];
	return x;
}
void work(int k,int x,rec a){
	if (k >= ans) return;
	f[k] = x;
	for (int i = 1;i <= 9;i++) a.v[i] = (a.v[i] + b[x][i]) & 3;
	if (sum(a) == 0){
		ans = k;
		for (int i = 1;i <= k;i++) g[i] = f[i];
		return;
	}
	for (int i = x;i <= 9;i++) if (i && (k <= 4 || f[k - 4] != i)) work(k + 1,i,a);
}
int main(){
	for (int i = 1;i <= 9;i++) scanf("%d",&a.v[i]);
	ans = 100;
	work(0,0,a);
	for (int i = 1;i < ans;i++) printf("%d ",g[i]);
	printf("%d\n",g[ans]);
}