/*
USER: courage2
LANG: C++
TASK: contact
*/
#include <cstdio>
#include <cstring>
char s[110],t[200010];
int a[200010],f[13][4100] = {{0}},A,B,n,l,x,y;
void p(int k,int x){
	for (int i = k - 1;i >= 0;i--) printf("%d",(x >> i) & 1);
}
int main(){
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	scanf("%d%d%d",&A,&B,&n);
	while (scanf("%s",s) != EOF) strcat(t,s);
	l = strlen(t);
	for (int i = 1;i <= l;i++) a[i] = t[i - 1] - '0';
	for (int k = A;k <= B;k++)
		for (int i = 1;i + k - 1 <= l;i++){
			x = 0;
			for (int j = i;j < i + k;j++) x = (x << 1) + a[j];
			f[k][x]++;
		}
	while (n--){
		x = 0;
		for (int i = A;i <= B;i++)
			for (int j = 0;j <= (1 << B);j++) if (x < f[i][j]) x = f[i][j];
		if (!x) break;
		printf("%d\n",x);
		y = 0;
		for (int i = A;i <= B;i++)
			for (int j = 0;j <= (1 << B);j++) if (x == f[i][j]){
				f[i][j] = 0;
				if (y % 6) printf(" ");
				p(i,j);
				if (y % 6 == 5) printf("\n");
				y++;
			}
		if (y % 6) printf("\n");
	}
}
