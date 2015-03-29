#include <cstdio>
int f[1010],x[1010],y[1010],n,d,p,q;
bool v[1010] = {0};
char s[3];
bool yes(int i,int j){
	return ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= d * d);
}
int father(int x){
	if (f[x] == x) return x;
	f[x] = father(f[x]);
	return f[x];
}
int main(){
	scanf("%d%d",&n,&d);
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= n;i++) scanf("%d%d",&x[i],&y[i]);
	while (scanf("%s",s) != EOF)
		if (s[0] == 'S'){
			scanf("%d%d",&p,&q);
			if (father(p) == father(q)) printf("SUCCESS\n");else printf("FAIL\n");
		}else{
			scanf("%d",&p);
			if (v[p]) continue;
			v[p] = 1;
			for (int i = 1;i <= n;i++) if (i != p && v[i] && yes(i,p))
				if (father(p) != father(i)) f[father(p)] = father(i);
		}
}