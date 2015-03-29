/*
USER: courage2
LANG: C++
TASK: milk4
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
int n,m,k,a[110],b[110],ans[110];
bool f[20010];
bool search(int k,int x,int mx){
	b[k] = a[x];
	if (k == mx){
		memset(f,0,sizeof f);
		f[0] = 1;
		for (int i = 1;i <= k;i++) if (!f[b[i]]){
			for (int j = b[i];j <= m;j++) f[j] |= f[j - b[i]];
		}
		if (f[m]){
			for (int i = 1;i <= k;i++) ans[i] = b[i];
		}
		return f[m];
	}
	for (int i = x + 1;i <= n;i++) if (search(k + 1,i,mx)) return 1;
	return 0;
}
int main(){
	freopen("milk4.in","r",stdin);
	freopen("milk4.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	std::sort(a + 1,a + n + 1);
	
	for (int i = 1;i <= n;i++) if (search(0,0,i)){
		k = i;
		break;
	}
	printf("%d",k);
	for (int i = 1;i <= k;i++) printf(" %d",ans[i]);
	printf("\n");
}
