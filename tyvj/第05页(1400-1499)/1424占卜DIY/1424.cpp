#include <cstdio>
char s[3];
int a[20][5] = {{0}},f[20] = {0};
bool end = 0;
void swap(int & a,int & b){
	int t = a;
	a = b;
	b = t;
}
void push(int x){
	f[x]++;
	if (x == 13 && f[13] == 5) return;
	int k = 4;
	while (a[x][k] == 0) k--;
	int y = a[x][k];
	a[x][k] = 0;
	push(y);
}
int main(){
	for (int i = 1;i <= 13;i++)
		for (int j = 1;j <= 4;j++){
			scanf("%s",s);
			if ('2' <= s[0] && s[0] <= '9') a[i][j] = s[0] - '0';
			if (s[0] == 'A') a[i][j] = 1;
			if (s[0] == '0') a[i][j] = 10;
			if (s[0] == 'J') a[i][j] = 11;
			if (s[0] == 'Q') a[i][j] = 12;
			if (s[0] == 'K') a[i][j] = 13;
		}
	swap(a[13][1],a[13][4]);
	swap(a[13][2],a[13][3]);
	push(13);
	int ans = 0;
	for (int i = 1;i <= 12;i++) ans += (f[i] == 4);
	printf("%d\n",ans);
}
