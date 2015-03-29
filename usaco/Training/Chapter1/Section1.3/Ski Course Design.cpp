/*
USER: courage2
LANG: C++
TASK: skidesign
*/
#include <cstdio>
#include <algorithm>
int n,a[1010],ans,min,max;
int sqr(int x){
	return x * x;
}
int count(int low,int h){
	if (h < low) return sqr(low - h);
	if (h > low + 17) return sqr(h - low - 17);
	return 0;
}
int main(){
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",a + i);
	std::sort(a + 1,a + n + 1);
	ans = 1e9;
	if (a[n] - a[1] <= 17)
		ans = 0;
	else
		for (int low = a[1];low <= a[n] - 17;low++){
			int tmp = 0;
			for (int i = 1;i <= n;i++) tmp += count(low,a[i]);
			if (tmp < ans) ans = tmp;
		}
	printf("%d\n",ans);
}
