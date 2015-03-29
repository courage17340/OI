/*
USER: courage2
LANG: C++
TASK: wissqu
*/
#include <cstdio>
int a[5][5],f[6] = {0,3,3,3,4,3},ans = 0,x[20],y[20],z[20];
bool v[5][5] = {{0}};
char s[10];
bool yes(int x,int y,int z){
	if (v[x][y]) return 0;
	for (int i = x - 1;i <= x + 1;i++)
		for (int j = y - 1;j <= y + 1;j++)
			if (i >= 1 && i <= 4 && j >= 1 && j <= 4 && a[i][j] == z) return 0;
	return 1;
}
void out(){
	for (int i = 1;i <= 16;i++) printf("%c %d %d\n",z[i] + 'A' - 1,x[i],y[i]);
}
void search(int k,int p,int q,int c){
	x[k] = p;
	y[k] = q;
	z[k] = c;
	if (k == 16){
		ans++;
		if (ans == 1) out();
		return;
	}
	v[p][q] = 1;
	int tmp = a[p][q];
	a[p][q] = c;
	f[c]--;
	for (int r = 1;r <= 5;r++) if (f[r])
		for (int i = 1;i <= 4;i++)
			for (int j = 1;j <= 4;j++) if (yes(i,j,r)) search(k + 1,i,j,r);
	a[p][q] = tmp;
	f[c]++;
	v[p][q] = 0;
}
int main(){
	freopen("wissqu.in","r",stdin);
	freopen("wissqu.out","w",stdout);
	for (int i = 1;i <= 4;i++){
		scanf("%s",s);
		for (int j = 1;j <= 4;j++) a[i][j] = s[j - 1] - 'A' + 1;
	}
	for (int i = 1;i <= 4;i++)
		for (int j = 1;j <= 4;j++) if (yes(i,j,4)) search(1,i,j,4);
	printf("%d\n",ans);
}
