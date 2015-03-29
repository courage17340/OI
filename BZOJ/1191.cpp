#include <cstdio>
#include <cstring>
int n,m,b[1010][2],ans,link[1010];
bool a[1010][1010] = {{0}},v[1010] = {0};
bool find(int x){
	for (int i = 0;i < m;i++) if (a[x][i] && !v[i]){
		v[i] = 1;
		if (link[i] == 0 || find(link[i])){
			link[i] = x;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d",&b[i][0],&b[i][1]);
		a[i][b[i][0]] = a[i][b[i][1]] = 1;
	}
	ans = 0;
	for (int i = 1;i <= n;i++){
		memset(v,0,sizeof v);
		if (find(i)) ans++;else break;
	}
	printf("%d",ans);
}
