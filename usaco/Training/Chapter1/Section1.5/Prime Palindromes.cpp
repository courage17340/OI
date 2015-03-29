/*
ID: courage2
PROG: pprime
LANG: C++
*/
#include <cstdio>
int a,b,l1,l2,x,f[10];
bool flag = 0;
bool p(int x){
	for (int i = 2;i * i <= x;i++) if (x % i == 0) return 0;
	return 1;
}
void work(int l,int r,int x,int q){
	if (flag) return;
	f[l] = f[r] = x;
	if (l + 1 < r) for (int i = 0;i <= 9;i++) work(l + 1,r - 1,i,q);
	else{
		int t = 0;
		for (int i = 1;i <= q;i++) t = t * 10 + f[i];
		if (t > b){
			flag = 1;
			return;
		}
		if (t < a) return;
		if (p(t)) printf("%d\n",t);
	}
}
int main(){
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	scanf("%d%d",&a,&b);
	x = 1;
	l1 = 0;
	while (x <= a){
		x *= 10;
		l1++;
	}
	x = 1;
	l2 = 0;
	while (x <= b){
		x *= 10;
		l2++;
	}
	for (int l = l1;l <= l2;l++) for (int i = 1;i <= 9;i += 2) work(1,l,i,l);
}
