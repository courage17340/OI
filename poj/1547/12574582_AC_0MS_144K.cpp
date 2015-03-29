#include <cstdio>
char s[10][10];
int n,p,q,a[10],x,y,z;
int main(){
	while (1){
		scanf("%d",&n);
		if (n < 0) break;
		p = q = 1;
		scanf("%d%d%d%s",&x,&y,&z,s[1]);
		a[1] = x * y * z;
		for (int i = 2;i <= n;i++){
			scanf("%d%d%d%s",&x,&y,&z,s[i]);
			a[i] = x * y * z;
			if (a[i] > a[p]) p = i;
			if (a[i] < a[q]) q = i;
		}
		printf("%s took clay from %s.\n",s[p],s[q]);
	}
}