/*
USER: courage2
LANG: C++
TASK: window
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
struct rec{
	int x1,y1,x2,y2,c,h;
};
bool cmp(rec a,rec b){
	return a.h < b.h;
}
rec a[100];
char c;
int n,ans;
template <class T>
void Swap(T &a,T &b){
	T c;
	c = a;
	a = b;
	b = c;
}
int min(int a,int b){
	return a < b ? a : b;
}
int max(int a,int b){
	return a > b ? a : b;
}
int work(int k,int x1,int y1,int x2,int y2){
	if (x1 >= x2 || y1 >= y2) return 0;
	if (k > n) return (x2 - x1) * (y2 - y1);
	int ret = 0;
	if (x1 < a[k].x1) ret += work(k + 1,x1,y1,min(x2,a[k].x1),y2);
	if (x2 > a[k].x2) ret += work(k + 1,max(x1,a[k].x2),y1,x2,y2);
	if (y1 < a[k].y1) ret += work(k + 1,max(x1,a[k].x1),y1,min(x2,a[k].x2),min(y2,a[k].y1));
	if (y2 > a[k].y2) ret += work(k + 1,max(x1,a[k].x1),max(y1,a[k].y2),min(x2,a[k].x2),y2);
	return ret;
}
int main(){
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	n = 0;
	while (scanf("%c",&c) != EOF){
		if (c == 'w'){
			n++;
			scanf("%*c%c,%d,%d,%d,%d%*c%*c",&c,&a[n].x1,&a[n].y1,&a[n].x2,&a[n].y2);
			a[n].c = c;
			if (a[n].x1 > a[n].x2) Swap(a[n].x1,a[n].x2);
			if (a[n].y1 > a[n].y2) Swap(a[n].y1,a[n].y2);
			a[n].h = 0;
			for (int i = 1;i < n;i++) a[n].h = max(a[n].h,a[i].h + 1);
		}else if (c == 't'){
			scanf("%*c%c%*c%*c",&c);
			for (int i = 1;i <= n;i++) if (c == a[i].c){
				for (int j = 1;j <= n;j++) if (i != j) a[i].h = max(a[i].h,a[j].h + 1);
				break;
			}
		}else if (c == 'b'){
			scanf("%*c%c%*c%*c",&c);
			for (int i = 1;i <= n;i++) if (c == a[i].c){
				for (int j = 1;j <= n;j++) if (i != j) a[i].h = min(a[i].h,a[j].h - 1);
				break;
			}
		}else if (c == 'd'){
			scanf("%*c%c%*c%*c",&c);
			for (int i = 1;i <= n;i++) if (c == a[i].c){
				for (int j = i;j < n;j++) a[j] = a[j + 1];
				break;
			}
			n--;
		}else{
			scanf("%*c%c%*c%*c",&c);
			std::sort(a + 1,a + n + 1,cmp);
			for (int i = 1;i <= n;i++) if (a[i].c == c){
				double s = (a[i].x2 - a[i].x1) * (a[i].y2 - a[i].y1);
				ans = work(i + 1,a[i].x1,a[i].y1,a[i].x2,a[i].y2);
				printf("%.3f\n",100.0 * ans / s);
				break;
			}
		}
	}
}
