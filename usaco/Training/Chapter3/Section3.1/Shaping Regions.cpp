/*
USER: courage2
LANG: C++
TASK: rect1
*/
#include <cstdio>
struct rec{
	int x1,x2,y1,y2,c;
};
rec a[1010],f[100010];
int n,m,k,p,ans[2510] = {0};
int min(int a,int b){
	return a < b ? a : b;
}
int max(int a,int b){
	return a > b ? a : b;
}
void up(int x1,int y1,int x2,int y2,int k,int c){
	if (x1 >= x2 || y1 >= y2) return;
	if (k == 0){
		p++;
		f[p].x1 = x1;
		f[p].y1 = y1;
		f[p].x2 = x2;
		f[p].y2 = y2;
		f[p].c = c;
		return;
	}
	if (x1 < f[k].x1) up(x1,y1,min(x2,f[k].x1),y2,k - 1,c);
	if (x2 > f[k].x2) up(max(f[k].x2,x1),y1,x2,y2,k - 1,c);
	if (y1 < f[k].y1) up(max(x1,f[k].x1),y1,min(x2,f[k].x2),min(y2,f[k].y1),k - 1,c);
	if (y2 > f[k].y2) up(max(x1,f[k].x1),max(y1,f[k].y2),min(x2,f[k].x2),y2,k - 1,c);
}
int main(){
	freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	k++;
	a[k].x1 = a[k].y1 = 0;
	a[k].x2 = n;
	a[k].y2 = m;
	a[k].c = 1;
	for (int i = k - 1;i >= 1;i--) scanf("%d%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,&a[i].c);
	f[p = 1] = a[1];
	for (int i = 2;i <= k;i++) up(a[i].x1,a[i].y1,a[i].x2,a[i].y2,p,a[i].c);
	for (int i = 1;i <= p;i++) ans[f[i].c] += (f[i].x2 - f[i].x1) * (f[i].y2 - f[i].y1);
	for (int i = 1;i <= 2500;i++) if (ans[i]) printf("%d %d\n",i,ans[i]);
}
