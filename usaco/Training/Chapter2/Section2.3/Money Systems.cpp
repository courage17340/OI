/*
ID: courage2
TASK: money
LANG: C++
*/
#include <cstdio>
typedef long long ll;
ll f[10010] = {1};
int n,m,x;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d%d",&n,&m);
	while (n--){
		scanf("%d",&x);
		for (int i = x;i <= m;i++) f[i] += f[i - x];
	}
	printf("%lld\n",f[m]);
}
