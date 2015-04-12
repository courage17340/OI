#include <cstdio>
int t,n,m,ans,x;
char s[1010];
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%d",&m);
		n = 0;
		ans = 0;
		scanf("%s",s);
		for (int i = 0;i <= m;++i){
			if (n < i){
				ans += i - n;
				n = i;
			}
			n += s[i] - '0';
		}
		printf("Case #%d: %d\n",T,ans);
	}
}
