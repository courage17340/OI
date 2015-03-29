#include <cstdio>
#include <cstring>
const int N = 1000000;
int f[N * 2 + 10],l,r,n,x,y,ans;
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	memset(f,200,sizeof f);
	scanf("%d",&n);
	f[N] = 0;
	l = r = N;
	while (n--){
		scanf("%d%d",&x,&y);
		if (x <= 0 && y <= 0) continue;
		if (x > 0){
			for (int i = r + x;i >= l + x;i--) f[i] = max(f[i],f[i - x] + y);
			r += x;
		}else{
			for (int i = l + x;i <= r + x;i++) f[i] = max(f[i],f[i - x] + y);
			l += x;
		}
	}
	ans = N + f[N];
	for (int i = N + 1;i <= r;i++) if (f[i] >= 0) ans = max(ans,i + f[i]);
	ans -= N;
	printf("%d",ans);
}
