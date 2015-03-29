/*
ID: courage2
LANG: C++
PROG: transform
*/
#include <cstdio>
int n;
char a[20][20],b[20][20];
bool rot_90(){
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++) if (a[i][j] != b[j][n - i - 1]) return 0;
	return 1;
}
bool rot_180(){
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++) if (a[i][j] != b[n - i - 1][n - j - 1]) return 0;
	return 1;
}
bool rot_270(){
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++) if (b[i][j] != a[j][n - i - 1]) return 0;
	return 1;
}
bool same(){
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++) if (a[i][j] != b[i][j]) return 0;
	return 1;
}
void swap(char & a,char & b){
	char t = a;
	a = b;
	b = t;
}
int work(){
	if (rot_90()) return 1;
	if (rot_180()) return 2;
	if (rot_270()) return 3;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n - j - 1;j++) swap(a[i][j],a[i][n - j - 1]);
	if (same()) return 4;
	if (rot_90() || rot_180() || rot_270()) return 5;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n - j - 1;j++) swap(a[i][j],a[i][n - j - 1]);
	if (same()) return 6;
	return 7;
}
int main(){
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0;i < n;i++) scanf("%s",a[i]);
	for (int i = 0;i < n;i++) scanf("%s",b[i]);
	printf("%d\n",work());
}
