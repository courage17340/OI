#include <cstdio>
#include <cstring>
#include <algorithm>
int n,a[10010],b[10010],f[300],ans;
char s[300];
int g(const char * s){
	int n = strlen(s),p = 1,l,r,m;
	f[1] = s[0];
	for (int i = 1;i < n;i++) if (s[i] > f[p]) f[++p] = s[i];else{
		l = 1;
		r = p;
		while (l < r){
			m = (l + r) >> 1;
			if (f[m] < s[i]) l = m + 1;else r = m;
		}
		f[l] = s[i];
	}
	return p;
}
bool cmp(int a,int b){
	return a > b;
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%s%d",s,&b[i]);
		a[i] = g(s);
	}
	std::sort(a + 1,a + n + 1);
	std::sort(b + 1,b + n + 1,cmp);
	ans = 0;
	for (int i = 1;i <= n;i++) ans += a[i] * b[i];
	printf("%d",ans);
}
