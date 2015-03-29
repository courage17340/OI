/*
ID: courage2
TASK: inflate
LANG: C++
*/
#include <cstdio>
int n,m,x,y,f[10010] = {0};
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	scanf("%d%d",&m,&n);
	while (n--){
		scanf("%d%d",&x,&y);
		for (int i = y;i <= m;i++) f[i] = max(f[i],f[i - y] + x);
	}
	printf("%d\n",f[m]);
}
