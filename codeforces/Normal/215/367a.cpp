#include <cstdio>
#include <cstring>
#include <algorithm>
char s[100010];
int l,m,x,y,f[100010][3]={{0}},a[3];
bool yes(int a,int b,int c){
	if (a + b + c <= 2) return 1;
	return (c - a <= 1);
}
int main(){
	scanf("%s%d",s,&m);
	l = strlen(s);
	for (int i = 0;i < l;i++){
		f[i + 1][0] = f[i][0];
		f[i + 1][1] = f[i][1];
		f[i + 1][2] = f[i][2];
		f[i + 1][s[i] - 'x']++;
	}
	while (m--){
		scanf("%d%d",&x,&y);
		a[0] = f[y][0] - f[x - 1][0];
		a[1] = f[y][1] - f[x - 1][1];
		a[2] = f[y][2] - f[x - 1][2];
		std::sort(a,a + 3);
		if (yes(a[0],a[1],a[2])) printf("YES\n");else printf("NO\n");
	}
}
