/*
ID: courage2
LANG: C++
PROG: dualpal
*/
#include <cstdio>
#include <cstring>
int n,s,f[40],k,t;
bool yes(int x,int k){
	int p = 0;
	memset(f,0,sizeof(f));
	while (x){
		f[++p] = x % k;
		x /= k;
	}
	for (int i = 1;i * 2 <= p;i++) if (f[i] != f[p + 1 - i]) return 0;
	return 1;
}
int main(){
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	scanf("%d%d",&n,&s);
	k = 0;
	while (k < n){
		s++;
		t = 0;
		for (int i = 2;i <= 10;i++){
			if (yes(s,i)) t++;
			if (t >= 2){
				k++;
				printf("%d\n",s);
				break;
			}
		}
	}
}
