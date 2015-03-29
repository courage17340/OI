/*
ID: courage2
PROG: calfflac
LANG: C++
*/
#include <cstdio>
#include <cstring>
char s[200010],c;
int l,n,m,ans,a[20010],x,y;
char up(char c){
	if (c >= 'a') c = c - 'a' + 'A';
	return c;
}
void work(int x0,int x1){
	int p = x0,q = x1;
	while (p > 1 && q < n && up(s[a[p - 1]]) == up(s[a[q + 1]])){
		p--;
		q++;
	}
	if (ans < q - p + 1){
		ans = q - p + 1;
		x = a[p];
		y = a[q];
	}
}
int main(){
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	l = 0;
	while (scanf("%c",&c) != EOF) s[++l] = c;
	n = 0;
	for (int i = 1;i <= l;i++) if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z') a[++n] = i;
	ans = 1;
	x = y = a[1];
	for (int i = 2;i <= n;i++) work(i,i);
	for (int i = 2;i <= n;i++) if (s[a[i]] == s[a[i + 1]]) work(i,i + 1);
	printf("%d\n",ans);
	for (int i = x;i <= y;i++) printf("%c",s[i]);
	printf("\n");
}
