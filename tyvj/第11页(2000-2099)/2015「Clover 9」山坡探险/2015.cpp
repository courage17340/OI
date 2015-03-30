#include <cstdio>
#include <cstring>
int n,x,y,l,k,m;
char s[100010];
int abs(int x){
	return x > 0 ? x : -x;
}
int main(){
	scanf("%d%d%d%s",&n,&x,&y,s);
	if ((y - x - n) & 1){
		puts("T_T");
		return 0;
	}
	l = strlen(s);
	k = m = x;
	for (int i = 0;i < l;i++)
		if (s[i] == 'U')
			k++;
		else{
			k--;
			if (m > k) m = k;
		}
	n -= l;
	if (m < 0){
		n += m;
		k -= m;
	}
	if (abs(k - y) <= n)
		puts("lala");
	else
		puts("T_T");
}
