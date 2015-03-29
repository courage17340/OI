/*
USER: courage2
LANG: C++
TASK: picture
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
struct line{int l,r,x,f;};
bool cmp(line a,line b){
	return a.x < b.x || (a.x == b.x && a.f < b.f);
}
int n,x1,y1,x2,y2,p,ans = 0,f[20010];
line a[10010],b[10010];
void work(line a[]){
	std::sort(a + 1,a + n + 1,cmp);
	memset(f,0,sizeof f);
	for (int i = 1;i <= n;i++){
		if (a[i].f){
			for (int j = a[i].l;j < a[i].r;j++){
				f[j + 10000]--;
				if (!f[j + 10000]) ans++;
			}
		}else{
			for (int j = a[i].l;j < a[i].r;j++){
				f[j + 10000]++;
				if (f[j + 10000] == 1) ans++;
			}
		}
	}
}
int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d",&n);
	p = 0;
	for (int i = 1;i <= n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		p++;
		a[p].l = x1;
		a[p].r = x2;
		a[p].x = y1;
		a[p].f = 0;
		b[p].l = y1;
		b[p].r = y2;
		b[p].x = x1;
		b[p].f = 0;
		
		p++;
		a[p].l = x1;
		a[p].r = x2;
		a[p].x = y2;
		a[p].f = 1;
		b[p].l = y1;
		b[p].r = y2;
		b[p].x = x2;
		b[p].f = 1;
	}
	n *= 2;
	work(a);
	work(b);
	printf("%d\n",ans);
}
