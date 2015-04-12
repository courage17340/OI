#include <cstdio>
int t,x,r,c;
char s[2][10] = {"RICHARD","GABRIEL"};
int Min(int a,int b){
	return a < b ? a : b;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%d%d%d",&x,&r,&c);
		bool flag = 0;
		if (x == 1) flag = 1;
		if (x == 2 && r * c % 2 == 0) flag = 1;
		if (x == 3 && r * c % 3 == 0 && Min(r,c) > 1) flag = 1;
		if (x == 4 && r * c % 4 == 0 && Min(r,c) > 2) flag = 1;
		if (x == 5 && r * c % 5 == 0 && Min(r,c) > 2) flag = 1;
		if (x == 6 && r * c % 6 == 0 && Min(r,c) > 3) flag = 1;
		printf("Case #%d: %s\n",T,s[flag]);
	}
}
