/*数据有误，第一个代码能AC，第二个代码应该是正解（但是不能AC） 
#include <cstdio>
int main(){
int x;
	scanf("%d",&x);
	printf("%d",x);
}
*/

#include <cstdio>
#include <algorithm>
typedef long long ll;
int n,l,r,a[10],b[100010],p,q;
int f(ll x){
	int y = 0;
	while (x){
		y += x % 10;
		x /= 10;
	}
	return y;
}
void work(int p,int x,int s){
	a[p] = x;
	if (p == 9){
		int y = 0;
		for (int i = 1;i <= 9;i++) y = y * 10 + a[i];
		if (f((ll)y * y) == f(y) * f(y)) b[++n] = y;
		return;
	}
	for (int i = 0;i <= 3;i++) if (i + s < 13) work(p + 1,i,s + i);
}
int main(){
	n = 0;
	work(0,0,0);
	b[0] = 0;
	b[++n] = 1e9;
	std::sort(b + 1,b + n + 1);
	if (scanf("%d%d",&l,&r) != 2){
		r = l;
		l = 1;
	}
	p = 1;
	q = n;
	while (b[p] < l) p++;
	while (b[q] > r) q--;
	printf("%d\n",q - p + 1);
}
