#include <cstdio>
int x,y,k,ans,f[20] = {0};
bool g;
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	while (scanf("%d%d",&x,&y) != EOF){
		ans = -1;
		k = 0;
		y = -y;
		for (int i = 0;i < 4096;i++){
			for (int j = 1;j <= 12;j++) f[j] = f[j - 1] + (((i >> (j - 1)) & 1) ? x : y);
			g = 1;
			for (int j = 5;j <= 12;j++) if (f[j] - f[j - 5] >= 0) g = 0;
			if (!g) continue;
			ans = max(ans,f[12]);
		}
		if (ans >= 0) printf("%d\n",ans);else printf("Deficit\n");
	}
}