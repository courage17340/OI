/*
ID: courage2
LANG: C++
PROG: palsquare
*/
#include <cstdio>
char s[30] = "0123456789ABCDEFGHIJ";
int n,a[20],b[20],k,x,p,y,q;
bool yes(int x){
	p = 0;
	while (x){
		p++;
		a[p] = x % k;
		x /= k;
	}
	for (int i = 1;i <= p / 2;i++) if (a[i] != a[p + 1 - i]) return 0;
	return 1;
}
int main(){
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	scanf("%d",&k);
	for (int i = 1;i <= 300;i++){
		x = i * i;
		if (yes(x)){
			q = 0;
			y = i;
			while (y){
				q++;
				b[q] = y % k;
				y /= k;
			}
			for (int j = q;j >= 1;j--) printf("%c",s[b[j]]);
			printf(" ");
			for (int j = 1;j <= p;j++) printf("%c",s[a[j]]);
			printf("\n");
		}
	}
}
