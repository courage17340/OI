#include <cstdio>
#include <cstring>
#include <algorithm>
int f[110][1010],n,d,x,t,k;
bool flag;
struct rec{int t,h,l;};
rec a[110];
bool cmp(rec a,rec b){
	return a.t < b.t;
}
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	scanf("%d%d",&d,&n);
	memset(f,200,sizeof f);
	f[0][10] = 0;
	a[0].t = 0;
	for (int i = 1;i <= n;i++) scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].h);
	std::sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++){
		k = a[i].t - a[i - 1].t;
		for (int j = k;j <= 1000;j++){
			flag = 0;
			f[i][j - k] = max(f[i][j - k],f[i - 1][j] + a[i].h);
			if (f[i][j - k] >= d) flag = 1;
			if (j - k + a[i].l <= 1000){
				f[i][j - k + a[i].l] = max(f[i][j - k + a[i].l],f[i - 1][j]);
				if (f[i][j - k +a[i].l] >= d) flag = 1;
			}
			if (flag){
				printf("%d\n",a[i].t);
				return 0;
			}
		}
	}
	x = 10;
	t = 0;
	for (int i = 1;i <= n;i++) if (x >= a[i].t) x += a[i].l;else break;
	printf("%d\n",x);
}
