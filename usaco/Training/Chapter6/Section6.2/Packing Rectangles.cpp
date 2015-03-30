/*
ID: courage2
PROG: packrec
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
int a[5][2],x[5],y[5],f[3010],p,ans,l,r;
bool v[5] = {0};
void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}
int max(int a,int b){
	return a > b ? a : b;
}
int min(int a,int b){
	return a < b ? a : b;
}
void check(int s,int t){
	if (s > t) swap(s,t);
	if (s * t < ans){
		ans = s * t;
		p = 1;
		f[1] = s;
	}else if (s * t == ans) f[++p] = s;
}
void work1(){
	int s = 0,t = 0;
	for (int i = 1;i <= 4;i++){
		s += x[i];
		if (t < y[i]) t = y[i];
	}
	check(s,t);
}
void work2(){
	int s = 0,t = 0;
	for (int i = 1;i <= 3;i++) s += x[i];
	if (s < x[4]) s = x[4];
	for (int i = 1;i <= 3;i++) if (t < y[i]) t = y[i];
	t += y[4];
	check(s,t);
}
void work3(){
	int s,t;
	s = max(x[1] + x[2],x[4]) + x[3];
	t = max(y[3],y[4] + max(y[1],y[2]));
	check(s,t);
}
void work4(){
	int s,t;
	s = max(x[1],x[2]) + x[3] + x[4];
	t = max(max(y[1] + y[2],y[3]),y[4]);
	check(s,t);
}
void work5(){
	int s,t;
	s = max(x[1] + x[2],x[3] + x[4]);
	t = max(y[1] + y[3],y[2] + y[4]);
	if (x[2] > x[4] && y[3] > y[4]) t = max(y[1],y[2]) + y[3];
	if (x[1] > x[3] && y[3] < y[4]) t = max(y[1],y[2]) + y[4];
	check(s,t);
}
void search(int k,int p,int t){
	x[k] = a[p][t];
	y[k] = a[p][1 - t];
	v[p] = 1;
	if (k == 4){
		work1();
		work2();
		work3();
		work4();
		work5();
		v[p] = 0;
		return;
	}
	for (int i = 1;i <= 4;i++) if (!v[i]){
		search(k + 1,i,0);
		search(k + 1,i,1);
	}
	v[p] = 0;
}
int main(){
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	for (int i = 1;i <= 4;i++) scanf("%d%d",&a[i][0],&a[i][1]);
	p = 0;
	ans = 1e9;
	search(0,0,0);
	std::sort(f + 1,f + p + 1);
	l = 1;
	printf("%d\n",ans);
	while (l <= p){
		r = l;
		while (r < p && f[r + 1] == f[l]) r++;
		printf("%d %d\n",f[l],ans / f[l]);
		l = r + 1;
	}
}
