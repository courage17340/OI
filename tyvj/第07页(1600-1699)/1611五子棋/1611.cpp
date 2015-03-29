#include <cstdio>
char s[20][20];
int t,x;
int yes(){
	bool f;
	for (int i = 1;i <= 15;i++) for (int j = 0;j < 15;j++) if (s[i][j] != '.'){
		if (i + 4 <= 15){
			f = 1;
			for (int k = 1;k <= 4;k++) if (s[i + k][j] != s[i][j]) f = 0;
			if (f) return s[i][j];
		}
		if (j + 4 < 15){
			f = 1;
			for (int k = 1;k <= 4;k++) if (s[i][j + k] != s[i][j]) f = 0;
			if (f) return s[i][j];
		}
		if (i + 4 <= 15 && j + 4 < 15){
			f = 1;
			for (int k = 1;k <= 4;k++) if (s[i + k][j + k] != s[i][j]) f = 0;
			if (f) return s[i][j];
		}
		if (i > 4 && j + 4 < 15){
			f = 1;
			for (int k = 1;k <= 4;k++) if (s[i - k][j + k] != s[i][j]) f = 0;
			if (f) return s[i][j];
		}
	}
	return -1;
}
int main(){
	scanf("%d",&t);
	while (t--){
		for (int i = 1;i <= 15;i++) scanf("%s",s[i]);
		x = yes();
		if (x == -1) printf("I don't know.\n");else printf("%c win.\n",x);
	}
}
