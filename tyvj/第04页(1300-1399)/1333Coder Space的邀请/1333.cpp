#include <cstdio>
int f[1010][1010] = {{0}},ans,n,t,k,x,y;
int min(int a,int b){
	return a < b ? a : b;
}
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	scanf("%d%d",&n,&t);
	while (n--){
		scanf("%d%d",&x,&y);
		if (x > t && y > t) continue;
		if (x == 0 || y == 0){
			for (int i = t;i >= 0;i--) for (int j = t;j >= 0;j--) f[i][j]++;
			continue;
		}
		for (int i = t;i >= 0;i--)
			for (int j = t;j >= 0;j--){
				if (i >= x) f[i][j] = max(f[i][j],f[i - x][j] + 1);
				if (j >= y) f[i][j] = max(f[i][j],f[i][j - y] + 1);
			}
	}
	ans = f[t][t];
	if (ans == 0){
		printf("-1");
		return 0;
	}
	k = t;
	for (int i = 0;i <= t;i++)
		for (int j = 0;j <= t;j++) if (f[i][j] == ans) k = min(k,max(i,j));
	printf("%d\n%d",ans,k);
}
