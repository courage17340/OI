#include <cstdio>
#include <cstring>
int n,a[10010],b[10010] = {0},ans = 0;
bool f;
inline int max(int a,int b){
	return (a > b ? a : b);
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	f = 1;
	if (a[1] == 2) f = 0;
	for (int i = 2;i <= n;i++){
		if (!f) break;
		b[i] = a[i - 1] - b[i - 2] - b[i - 1];
		if (b[i] < 0) f = 0;
	}
	if (a[n] != b[n - 1] + b[n]) f = 0;
	if (f) ans++;
	b[1] = 1;
	f = 1;
	if (a[1] == 0) f = 0;
	for (int i = 2;i <= n;i++){
		if (!f) break;
		b[i] = a[i - 1] - b[i - 2] - b[i - 1];
		if (b[i] < 0) f = 0;
	}
	if (a[n] != b[n - 1] + b[n]) f = 0;
	if (f) ans++;
	printf("%d\n",ans);
}
