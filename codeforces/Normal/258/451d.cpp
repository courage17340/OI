#include <cstdio>
#include <cstring>
char s[100010];
int f[100010],x[2][2] = {{0}},l;
long long ans[2] = {0};
int main(){
	scanf("%s",s);
	l = strlen(s);
	f[0] = 0;
	f[1] = 1;
	for (int i = 1;i < l;i++) if (s[i] == s[i - 1]) f[i + 1] = f[i];else f[i + 1] = f[i] + 1;
	for (int i = 1;i <= l;i++){
		x[i & 1][f[i] & 1]++;
		ans[1] += x[i & 1][f[i] & 1];
		ans[0] += x[!(i & 1)][f[i] & 1];
	}
	printf("%I64d %I64d\n",ans[0],ans[1]);
}
