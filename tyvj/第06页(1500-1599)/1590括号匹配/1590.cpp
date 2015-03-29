#include <cstdio>
#include <cstring>
char a[2000010],s[16000010];
int n,l,p,max,k;
bool flag;
int main(){
	scanf("%d",&n);
	while (n--){
		p = 0;
		scanf("%s",a);
		l = strlen(a);
		flag = 1;
		max = 0;
		k = 0;
		for (int i = 0;i < l;i++){
			if (a[i] == '/' || a[i] == '(' || a[i] == '[' || a[i] == '{' || a[i] == '<') s[++p] = a[i];
			if (a[i] == '#') for (int j = 1;j <= 2;j++) s[++p] = '/';
			if (a[i] == '@') for (int j = 1;j <= 4;j++) s[++p] = '/';
			if (a[i] == '?') for (int j = 1;j <= 8;j++) s[++p] = '/';
			if (a[i] == ')') if (p && (s[p] == '(' || s[p] == '/')) p--;else{
				flag = 0;
				break;
			}
			if (a[i] == ']') if (p && (s[p] == '[' || s[p] == '/')) p--;else{
				flag = 0;
				break;
			}
			if (a[i] == '}') if (p && (s[p] == '{' || s[p] == '/')) p--;else{
				flag = 0;
				break;
			}
			if (a[i] == '>') if (p && (s[p] == '<' || s[p] == '/')) p--;else{
				flag = 0;
				break;
			}
			if (a[i] == '\\') if (p) p--;else{
				flag = 0;
				break;
			}
			if (a[i] == '*') if (p >= 2) p -= 2;else{
				flag = 0;
				break;
			}
			if (a[i] == '&') if (p >= 4) p -= 4;else{
				flag = 0;
				break;
			}
			if (a[i] == '!') if (p >= 8) p -= 8;else{
				flag = 0;
				break;
			}
			if (p > max){
				max = p;
				k = 1;
			}else if (p == max) k++;
		}
		if (p) flag = 0;
		if (flag) printf("TRUE %d %d\n",max,k);else printf("FALSE\n");
	}
}
