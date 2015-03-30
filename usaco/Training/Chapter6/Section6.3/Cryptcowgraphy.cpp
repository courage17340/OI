/*
USER: courage2
LANG:C++
TASK: cryptcow
*/
#include <cstdio>
#include <cstring>
char s0[] = "Begin the Escape execution at the Break of Dawn";
int l0 = strlen(s0);
char s[80],t[80];
int time = 0;
inline bool isCow(char c){
	return (c == 'C' || c == 'O' || c == 'W');
}
bool check(char *s){
	int l = strlen(s);
	for (int i = 0;i < l;i++) if (isCow(s[i])){
		for (int j = i + 1;j < l;j++) if (isCow(s[j])){
			if (j == i + 1) break;
			strncpy(t,s + i + 1,j - i - 1);
			t[j - i - 1] = 0;
			if (strstr(s0,t) == NULL) return 0;
			i = j - 1;
			break;
		}
	}
	for (int i = 0;i < l;i++) if (isCow(s[i])){
		if (!i) break;
		strncpy(t,s,i);
		t[i] = 0;
		if (strstr(s0,t) != s0) return 0;
		break;
	}
	for (int i = l - 1;i >= 0;i--) if (isCow(s[i])){
		if (i == l - 1) break;
		for (int j = i + 1;j < l;j++) if (s[j] != s0[j - l + l0]) return 0;
		break;
	}
	return 1;
}
bool work(char *s,int l){
	if (l == l0) return strcmp(s,s0) == 0;
	if (!check(s)) return 0;
	int I = 0,J = l - 1;
	while (!isCow(s[I])) I++;
	while (!isCow(s[J])) J--;
	if (s[I] != 'C' || s[J] != 'W') return 0;
	char ss[76];
	if (time > 22000) return 0;
	time++;
	for (int j = I + 1;j < J;j++) if (s[j] == 'O')
		for (int i = I;i < j;i++) if (s[i] == 'C')
			for (int k = J;k > j;k--) if (s[k] == 'W'){
				int p = -1;
				for (int q = 0;q < i;q++) ss[++p] = s[q];
				for (int q = j + 1;q < k;q++) ss[++p] = s[q];
				for (int q = i + 1;q < j;q++) ss[++p] = s[q];
				for (int q = k + 1;q < l;q++) ss[++p] = s[q];
				ss[p + 1] = 0;
				if (work(ss,l - 3)) return 1;
			}
	return 0;
}
bool wrong(){
	int l = strlen(s);
	if ((l - l0) % 3) return 1;
	int a[300] = {0};
	for (int i = 0;i < l0;i++) a[s0[i]]++;
	int x = (l - l0) / 3;
	a['C'] += x;
	a['O'] += x;
	a['W'] += x;
	for (int i = 0;i < l;i++) a[s[i]]--;
	for (int i = 1;i <= 127;i++) if (a[i] != 0) return 1;
	return !check(s);
}
int main(){
	freopen("cryptcow.in","r",stdin);
	freopen("cryptcow.out","w",stdout);
	scanf("%[^\n]%*c",s);
	if (wrong()){
		puts("0 0");
		return 0;
	}
	if (work(s,strlen(s))) printf("1 %d\n",(strlen(s) - l0) / 3);else printf("0 0\n");
}
