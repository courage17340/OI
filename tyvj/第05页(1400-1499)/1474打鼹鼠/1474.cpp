#include <cstdio>
struct rec{int x,y,k;};
rec a[10010];
int n,m,x1,y1,x2,y2,x,y,k,p,ans;
int main(){
	scanf("%d",&n);
	while (1){
		scanf("%d",&m);
		if (m == 3) break;
		if (m == 1){
			scanf("%d%d%d",&x,&y,&k);
			p++;
			a[p].x = x;
			a[p].y = y;
			a[p].k = k;
		}
		if (m == 2){
			ans = 0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for (int i = 1;i <= p;i++) if (x1 <= a[i].x && a[i].x <= x2 && y1 <= a[i].y && a[i].y <= y2) ans += a[i].k;
			printf("%d\n",ans);
		}
	}
}
