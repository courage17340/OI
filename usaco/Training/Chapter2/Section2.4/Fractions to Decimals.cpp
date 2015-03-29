/*
ID: courage2
TASK: fracdec
LANG: C++
*/
#include <cstdio>
#include <cstring>
bool v[100010] = {0};
char s[100010];
int a,b,p,f[100010] = {0};
void put(int x){
	int f[11] = {0},k = 0;
	if (!x) s[++p] = '0';
	while (x){
		f[++k] = x % 10;
		x /= 10;
	}
	for (int i = k;i >= 1;i--) s[++p] = f[i] + '0';
	s[++p] = '.';
}
void out(){
	p = strlen(s);
	for (int i = 0;i < p - 1;i++){
		putchar(s[i]);
		if (i % 76 == 75) putchar('\n');
	}
	putchar(s[p - 1]);
	putchar('\n');
}
int main(){
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	scanf("%d%d",&a,&b);
	p = -1;
	put(a / b);
	a %= b;
	if (!a){
		s[++p] = '0';
	}
	while (1){
		if (!a){
			s[++p] = 0;
			break;
		}
		if (v[a]){
			s[++p] = ')';
			s[++p] = 0;
			for (int i = 1;i < p;i++) if (f[i] == a){
				for (int j = p + 1;j > i + 1;j--) s[j] = s[j - 1];
				s[i + 1] = '(';
			}
			break;
		}
		f[p] = a;
		v[a] = 1;
		a *= 10;
		s[++p] = a / b + '0';
		a %= b;
	}
	out();
}
