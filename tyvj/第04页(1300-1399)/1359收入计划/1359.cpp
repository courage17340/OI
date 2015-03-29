#include <cstdio>
int n,m,a[100010],l,r,x,y;
int f(int x){
	int y = 0,t = 0;
	for (int i = 1;i <= n;i++){
		if (t + a[i] > x){
			t = 0;
			y++;
		}
		t += a[i];
		if (t > x) return 100000;
	}
	if (t) y++;
	return y;
}
int main(){
	scanf("%d%d",&n,&m);
	x = 0;
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		x += a[i];
	}
	l = 0;
	r = x;
	while (l != r){
		x = (l + r) >> 1;
		if (f(x) <= m) r = x;else l = x + 1;
	}
	printf("%d",l);
}
