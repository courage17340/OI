#include <cstdio>
const int N = 30000;
int f[N + 1],rank[N + 1] = {0},top[N + 1],t,x,y;
char s[3];
int father(int x){
	if (f[x] == x) return x;
	int y = f[x];
	f[x] = father(f[x]);
	rank[x] += rank[y];
	return f[x];
}
int main(){
	for (int i = 1;i <= N;i++) f[i] = top[i] = i;
	scanf("%d",&t);
	while (t--){
		scanf("%s",s);
		if (s[0] == 'M'){
			scanf("%d%d",&x,&y);
			if (father(x) != father(y)){
				rank[f[x]] = rank[top[f[y]]] + 1;
				top[f[y]] = top[f[x]];
				f[f[x]] = f[y];
			}
		}else{
			scanf("%d",&x);
			f[x] = father(x);
			printf("%d\n",rank[x]);
		}
	}
}