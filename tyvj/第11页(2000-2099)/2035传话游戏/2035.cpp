#include <cstdio>
#include <cstring>
bool a[1010][1010] = {{0}},v[1010],f[1010];
int n,m,x,y;
void search(int x){
	v[x] = 1;
	for (int i = 1;i <= n;i++) f[i] |= a[x][i];
	for (int i = 1;i <= n;i++) if (a[x][i] && !v[i]) search(i);
}
int main(){
	scanf("%d%d",&n,&m);
	while (m--){
		scanf("%d%d",&x,&y);
		a[x][y] = 1;
	}
	for (int i = 1;i <= n;i++){
		memset(v,0,sizeof v);
		memset(f,0,sizeof f);
		search(i);
		printf(f[i] ? "T\n" : "F\n");
	}
}
