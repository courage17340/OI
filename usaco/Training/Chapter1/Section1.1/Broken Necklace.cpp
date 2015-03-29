/*
ID: courage2
PROG: beads
LANG: C++
*/
#include <cstdio>
#include <cstring>
int n,ans,a[400],p,q,b1,b2,c1,e1,e2,c2,x;
char s[400];
inline int prev(int x){
	if (x == 1) return n;
	return x - 1;
}
inline int succ(int x){
	if (x == n) return 1;
	return x + 1;
}
int main(){
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s);
	for (int i = 1;i <= n;i++)
		if (s[i - 1] == 'w') a[i] = 0;else
			if (s[i - 1] == 'b') a[i] = 1;else a[i] = 2;
	ans  = 0;
	for (int i = 1;i <= n;i++){
		p = i;
		q = prev(i);
		if (a[p] == 0){
			b1 = 1;
			e1 = 2;
		}else b1 = e1 = a[p];
		if (a[q] == 0){
			b2 = 1;
			e2 = 2;
		}else b2 = e2 = a[q];
		for (c1 = b1;c1 <= e1;c1++) for (c2 = b2;c2 <= e2;c2++){
			x = 1;
			p = succ(i);
			q = prev(i);
			while ((a[p] == c1 || a[p] == 0) && p != succ(q)){
				x++;
				p = succ(p);
			}
			while ((a[q] == c2 || a[q] == 0) && q != prev(p)){
				x++;
				q = prev(q);
			}
			if (ans < x) ans = x;
		}
	}
	printf("%d\n",ans);
}
