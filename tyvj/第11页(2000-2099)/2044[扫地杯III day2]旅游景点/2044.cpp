#include <cstdio>
int f[100010],a[200010],b[200010],n,m,k,x,y,ans,p;
int father(int x){
	if (x == f[x]) return x;
	f[x] = father(f[x]);
	return f[x];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++) f[i] = i;
	p = ans = 0;
	while (m--){
		scanf("%d%d",&x,&y);
		if (x <= k || y <= k){
			p++;
			a[p] = x;
			b[p] = y;
			continue;
		}
		if (father(x) != father(y)) f[father(x)] = father(y);
	}
	for (int i = 1;i <= p;i++) if (father(a[i]) == father(b[i])) ans++;else f[father(a[i])] = father(b[i]);
	printf("%d\n",ans);
}
