/*
ID: courage2
TASK: concom
LANG: C++
*/
#include <cstdio>
#include <cstring>
int a[110][110] = {{0}},n,x,y,z,N = 0,f[110] = {0};
bool v[110] = {0};
void search(int x){
	v[x] = 1;
	for (int i = 1;i <= N;i++) f[i] += a[x][i];
	for (int i = 1;i <= N;i++) if (f[i] > 50 && !v[i]) search(i);
}
int main(){
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d%d",&x,&y,&z);
		if (N < x) N = x;
		if (N < y) N = y;
		a[x][y] = z;
	}
	for (int i = 1;i <= N;i++){
		memset(f,0,sizeof f);
		memset(v,0,sizeof v);
		search(i);
		for (int j = 1;j <= N;j++) if (i != j && f[j] > 50) printf("%d %d\n",i,j);
	}
}
