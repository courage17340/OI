#include <cstdio>
#include <algorithm>
int n,m,a[3010];
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m;i++) scanf("%d",&a[i]);
	std::sort(a + 1,a + m + 1);
	if (a[1] == 1 || a[m] == n){
		printf("NO\n");
		return 0;
	}
	for (int i = 1;i < m - 1;i++) if (a[i + 1] == a[i] + 1 && a[i + 2] == a[i] + 2){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
}
