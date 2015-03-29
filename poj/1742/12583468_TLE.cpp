#include <cstdio>
#include <cstring>
int n,m,x,y,k,t,ans,a[110],b[110];
bool f[100010];
int main(){
	while (1){
		scanf("%d%d",&n,&m);
		if (!n) break;
		memset(f,0,sizeof f);
		f[0] = 1;
		for (int i = 1;i <= n;i++) scanf("%d",a + i);
		for (int i = 1;i <= n;i++) scanf("%d",b + i);
		for (int q = 1;q <= n;q++){
			x = a[q];
			y = b[q];
			t = 1;
			while (y > 0){
				if (y < t) t = y;
				k = x * t;
				for (int i = m;i >= k;i--) f[i] |= f[i - k];
				y -= t;
				t <<= 1;
			}
		}
		ans = 0;
		for (int i = 1;i <= m;i++) ans += f[i];
		printf("%d\n",ans);
	}
}