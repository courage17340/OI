#include<cstdio>
int f[10010],num[10010],n,m,k,x,y;
int father(int x){
	if (x == f[x]) return x;
	f[x] = father(f[x]);
	return f[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) num[i] = 1;
	for (int i = 1;i <= n;i++) f[i] = i;
	while (m--){
		scanf("%d",&k);
		if (k == 1){
			scanf("%d%d",&x,&y);
			if (father(x) == father(y)){
				printf("Yes\n");
				continue;
			}
			printf("No\n");
			num[father(x)] += num[father(y)];
			f[father(y)] = father(x);
		}else{
			scanf("%d",&x);
			printf("%d\n",num[father(x)] - 1);
		}
	}
}
