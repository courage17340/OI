/*
ID: courage2
PROG: frac1
LANG: C++
*/
#include <cstdio>
#include <algorithm>
int n,p = 0,t;
struct rec{int x,y;};
rec a[30000];
bool cmp(rec a,rec b){
	return a.x * b.y < b.x * a.y;
}
int gcd(int a,int b){
	if (b == 0) return a;
	return gcd(b,a % b);
}
int main(){
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0;i <= n;i++)
		for (int j = i;j <= n;j++){
			t = gcd(i,j);
			if (t != 1) continue;
			p++;
			a[p].x = i / t;
			a[p].y = j / t;
		}
	std::sort(a + 1,a + p + 1,cmp);
	for (int i = 1;i <= p;i++) printf("%d/%d\n",a[i].x,a[i].y);
}
