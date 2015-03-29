/*
ID: courage2
TASK: runround
LANG: C++
*/
#include <cstdio>
#include <cstring>
int x,a[20];
bool v[20];
bool f(int x){
	int p = 0,y;
	while (x){
		a[++p] = x % 10;
		if (a[p] == 0) return 0;
		x /= 10;
	}
	memset(v,0,sizeof v);
	for (int i = 1;i <= p;i++){
		if (v[a[i]]) return 0;
		v[a[i]] = 1;
	}
	memset(v,0,sizeof v);
	y = p;
	v[p] = 1;
	for (int i = 1;i <= p;i++){
		int j = a[y];
		while (j--){
			y--;
			if (y == 0) y = p;
		}
		if (y == p && i == p) return 1;
		if (v[y]) return 0;
		v[y] = 1;
	}
}
int main(){
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	scanf("%d",&x);
	x++;
	while (!f(x)) x++;
	printf("%d\n",x);
}
