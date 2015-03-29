/*
USER: courage2
LANG: C++
TASK: buylow
*/
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 500;
struct num{
	int p,v[N + 1];
	num(int x = 0){
		memset(v,0,sizeof v);
		p = N;
		while (x){
			v[p--] = x % 10;
			x /= 10;
		}
		if (p < N) p++;
	}
	num &operator =(const num &a){
		if (this == &a) return *this;
		p = a.p;
		for (int i = 0;i <= N;i++) v[i] = a.v[i];
		return *this;
	}
	num operator +(const num &a){
		num b;
		b.p = p;
		if (b.p > a.p) b.p = a.p;
		int j = 0;
		for (int i = N;i >= b.p;i--){
			j += v[i] + a.v[i];
			b.v[i] = j % 10;
			j /= 10;
		}
		while (j){
			b.v[--b.p] = j % 10;
			j /= 10;
		}
		return b;
	}
	void show(){
		for (int i = p;i <= N;i++) printf("%d",v[i]);
	}
};
int max(int a,int b){
	return a > b ? a : b;
}
int a[5010],f[5010],n,ans = 0;
num g[5010],ans2;
int main(){
	freopen("buylow.in","r",stdin);
	freopen("buylow.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	for (int i = 1;i <= n;i++) f[i] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 1;j < i;j++) if (a[i] < a[j]) f[i] = max(f[i],f[j] + 1);
	for (int i = 1;i <= n;i++) if (ans < f[i]) ans = f[i];
	for (int i = 1;i <= n;i++) if (f[i] == 1) g[i] = 1;
	for (int i = 1;i < n;i++)
		for (int j = i + 1;j <= n;j++) if (a[i] > a[j]){
			if (f[i] + 1 == f[j]) g[j] = g[i] + g[j];
		}else if (a[i] == a[j] && f[i] == f[j]) g[j] = 0;
	ans2 = 0;
	for (int i = 1;i <= n;i++) if (f[i] == ans) ans2 = ans2 + g[i];
	printf("%d ",ans);
	ans2.show();
	printf("\n");
}
