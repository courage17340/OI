#include <cstdio>
#include <algorithm>
struct rec{int x,y;};
bool operator <(rec a,rec b){
	return 300000ll * a.x + a.y < 300000ll * b.x + b.y;
}
rec a[20010];
using namespace std;
int n,x,y;
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a + 1,a + n + 1);
	x = a[1].x + a[n].x;
	y = a[1].y + a[n].y;
	for (int i = 1;i * 2 <= n;i++) if (a[i].x + a[n + 1 - i].x != x || a[i].y + a[n + 1 - i].y != y){
		printf("This is a dangerous situation!\n");
		return 0;
	}
	printf("V.I.P. should stay at (%.1f,%.1f).\n",x / 2.0,y / 2.0);
}
