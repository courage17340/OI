/*
USER: courage2
LANG: C++
TASK: hidden
*/
#include <cstdio>
#include <cstring>
char s[200010],t[100];
int n,p,q,k,x,y;
int main(){
	freopen("hidden.in","r",stdin);
	freopen("hidden.out","w",stdout);
	scanf("%d",&n);
	while (scanf("%s",t) != EOF) strcat(s,t);
	for (int i = 0;i < n;i++) s[n + i] = s[i];
	p = 0;
	q = 1;
	while (q < n){
		x = p;
		y = q;
		for (int i = 0;i < n;i++){
			if (s[x] > s[y]){
				p = q;
				q++;
				break;
			}else if (s[x] < s[y]){
				q += i + 1;
				break;
			}else{
				if (i == n - 1){
					puts("0");
					return 0;
				}
				x++;
				y++;
			}
		}
	}
	printf("%d\n",p);
}
