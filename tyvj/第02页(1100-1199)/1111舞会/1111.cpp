#include <cstdio>
int f[210],x,n,ans;
bool v[210] = {0};
int father(int x){
	if (f[x] == x) return x;
	f[x] = father(f[x]);
	return f[x];
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= n;i++)
		while (1){
			scanf("%d",&x);
			if (x == 0) break;
			if (father(x) != father(i)) f[father(x)] = father(i);
		}
	ans = 0;
	for (int i = 1;i <= n;i++) v[father(i)] = 1;
	for (int i = 1;i <= n;i++) ans += v[i];
	printf("%d\n",ans);
}
