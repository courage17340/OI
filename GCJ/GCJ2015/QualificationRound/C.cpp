#include <cstdio>
typedef long long ll;
int t,n,a[100010];
int tab[4][4] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
ll m;
char s[10010],ans[2][6] = {"NO","YES"};
int mul(int a,int b){
	int ret = 1;
	if (a < 0){
		a = -a;
		ret = -ret;
	}
	if (b < 0){
		b = -b;
		ret = -ret;
	}
	ret *= tab[a - 1][b - 1];
	return ret;
}
int find(char c){
	if (c == '1') return 1;
	if (c == 'i') return 2;
	if (c == 'j') return 3;
	return 4;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%d%lld",&n,&m);
		scanf("%s",s);
		for (int i = 1;i <= n;++i) a[i] = find(s[i - 1]);
		int limi;
		if (m >= 9) limi = 9;else limi = m;
		limi *= n;
		for (int i = n + 1;i <= limi;++i) a[i] = a[i - n];
		int sing = 1;
		for (int i = 1;i <= n;++i) sing = mul(sing,a[i]);
		m %= 4;
		if (m == 0) sing = 1;
		if (m == 2) sing = mul(sing,sing);
		if (m == 3) sing = mul(sing,mul(sing,sing));
		if (sing != -1){
			printf("Case #%d: NO\n",T);
			continue;
		}
		bool flag = 1;
		int l = 0,cur = 1;
		while (cur != 2){
			++l;
			if (l > limi){
				flag = 0;
				break;
			}
			cur = mul(cur,a[l]);
		}
		cur = 1;
		while (cur != 3){
			++l;
			if (l > limi){
				flag = 0;
				break;
			}
			cur = mul(cur,a[l]);
		}
		printf("Case #%d: %s\n",T,ans[flag]);
	}
}
