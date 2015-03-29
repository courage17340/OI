#include <cstdio>
#include <cstring>
int a[300],p,q,l;
char s[1010];
char up(char a){
	if (a <= 'Z') return a;
	return a - 'a' + 'A';
}
char down(char a){
	if (a >= 'a') return a;
	return a - 'A' + 'a';
}
int main(){
	scanf("%s",s);
	l = strlen(s);
	p = q = 0;
	while (p < l){
		if (s[p] == '<'){
			if (s[p + 1] == 'U'){
				a[++q] = 1;
				p += 3;
			}else if (s[p + 1] == 'D'){
				a[++q] = 2;
				p += 5;
			}else if (s[p + 2] == 'U'){
				q--;
				p += 4;
			}else{
				q--;
				p += 6;
			}
		}else{
			if (q)
				if (a[q] == 1) putchar(up(s[p]));else putchar(down(s[p]));
			else putchar(s[p]);
		}
		p++;
	}
}
