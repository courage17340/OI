#include <cstdio>
#include <cstring>
int l,p,q,w,a[30];
bool flag = 0;
char s[30];
void next(){
	int x = w;
	a[x]++;
	if (a[x] > q){
		x--;
		while (x > 0 && a[x] >= x - w + q) x--;
	}else return;
	if (x == 0){
		flag = 1;
		return;
	}
	a[x]++;
	for (int i = x + 1;i <= w;i++) a[i] = a[i - 1] + 1;
}
bool yes(){
	if (a[1] < p || a[w] > q) return 0;
	for (int i = 1;i < w;i++) if (a[i] >= a[i + 1]) return 0;
	return 1;
}
void out(){
	for (int i = 1;i <= w;i++) printf("%c",a[i] + 'a' - 1);
	printf("\n");
}
int main(){
	scanf("%d%d%d%s",&p,&q,&w,s);
	for (int i = 0;i < w;i++) a[i + 1] = s[i] - 'a' + 1;
	next();
	for (int i = 1;i <= 5;i++){
		while (!yes() && !flag) next();
		if (flag) return 0;
		out();
		next();
	}
}
