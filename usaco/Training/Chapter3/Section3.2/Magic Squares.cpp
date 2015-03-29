/*
USER: courage2
LANG: C++
TASK: msquare
*/
#include <cstdio>
#include <set>
using namespace std;
set<int> v;
int x,n,p,q,g[10];
char a[1010];
struct rec{int x,f,s,c;};
rec b[50000];
int A(int x){
	return x / 10000 + x % 10000 * 10000;
}
int B(int x){
	return x / 10000 % 10 * 10000000 + x / 100000 * 10000 + x % 10 * 1000 + x % 10000 / 10;
}
int C(int x){
	return x - x / 1000000 % 10 * 900000 + x / 100000 % 10 * (10 - 100000) + x / 100 % 10 * (1000000 - 100) + x / 10 % 10 * 90;
}
int f(int x,int t){
	t -= 'A';
	if (t == 0) return A(x);
	if (t == 1) return B(x);
	return C(x);
}
int main(){
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	n = 0;
	for (int i = 1;i <= 8;i++) scanf("%d",g + i);
	for (int i = 1;i <= 4;i++) n = n * 10 + g[i];
	for (int i = 8;i >= 5;i--) n = n * 10 + g[i];
	p = q = 1;
	b[1].x = 12348765;
	b[1].f = 0;
	b[1].c = 0;
	b[1].s = 0;
	v.insert(x);
	while (p <= q){
		if (b[p].x == n){
			x = p;
			printf("%d\n",b[p].s);
			a[b[p].s] = 0;
			for (int i = b[p].s;i >= 1;i--){
				a[i - 1] = b[x].c;
				x = b[x].f;
			}
			puts(a);
			break;
		}
		for (int i = 'A';i <= 'C';i++){
			x = f(b[p].x,i);
			if (!v.count(x)){
				q++;
				b[q].x = x;
				b[q].f = p;
				b[q].s = b[p].s + 1;
				b[q].c = i;
				v.insert(x);
			}
		}
		p++;
	}
}
