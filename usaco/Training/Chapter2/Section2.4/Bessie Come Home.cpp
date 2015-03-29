/*
ID: courage2
TASK: comehome
LANG: C++
*/
#include <cstdio>
#include <cstring>
int a[60][60],n,x,y,z;
char s[3],t[3];
int f(char c){
	if (c >= 'a') return c - 'a' + 1;
	return c - 'A' + 27;
}
char g(int x){
	return x - 27 + 'A';
}
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	memset(a,1,sizeof a);
	for (int i = 1;i <= 52;i++) a[i][i] = 0;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%s%s%d",s,t,&z);
		x = f(s[0]);
		y = f(t[0]);
		a[x][y] = min(a[x][y],z);
		a[y][x] = a[x][y];
	}
	for (int k = 1;k <= 52;k++)
		for (int i = 1;i <= 52;i++)
			for (int j = 1;j <= 52;j++) if (i != j){
				a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
			}
	x = 27;
	for (int i = 28;i < 52;i++) if (a[i][52] < a[x][52]) x = i;
	printf("%c %d\n",g(x),a[x][52]);
}
