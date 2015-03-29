#include <cstdio>
#include <cstring>
char s[3];
int a[1010][1010],b[1010][1010] = {{0}},c[1010],f[1010],g[1010],l[1010],r[1010],n,m,ans;
int max(int a,int b){
	return a > b ? a : b;
}
int get(int a[],int x,int r){
	if (a[x] > a[c[r]]) return x;
	if (a[x] <= a[c[1]]) return c[1];
	int l = 1,m;
	while (l != r){
		m = (l + r) >> 1;
		if (a[c[m]] >= a[x]) r = m;else l = m + 1;
	}
	return c[l];
}
void work(){
	int p = 1;
	c[1] = 1;
	l[1] = 1;
	for (int i = 2;i <= m;i++){
		l[i] = get(f,i,p);
		if (l[i] < i) l[i] = l[l[i]];
		while (p && f[i] < f[c[p]]) p--;
		c[++p] = i;
	}
	p = 1;
	c[1] = 1;
	r[1] = 1;
	for (int i = 2;i <= m;i++){
		r[i] = get(g,i,p);
		if (r[i] < i) r[i] = r[r[i]];
		while (p && g[i] < g[c[p]]) p--;
		c[++p] = i;
	}
	int x = 0;
	for (int i = 1;i <= m;i++) x = max(x,(m + 2 - l[i] - r[m + 1 - i]) * f[i]);
	ans = max(ans,x);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++){
			scanf("%s",s);
			a[i][j] = (s[0] == 'F');
		}
	for (int i = n;i >= 1;i--)
		for (int j = 1;j <= m;j++) if (!a[i][j]) b[i][j] = 0;else b[i][j] = b[i + 1][j] + 1;
	ans = 0;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++) f[j] = g[m + 1 - j] = b[i][j];
		work();
	}
	printf("%d\n",ans * 3);
}
