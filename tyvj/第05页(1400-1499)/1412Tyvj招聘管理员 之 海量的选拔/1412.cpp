#include <cstdio>
#include <cstring>
int f[20010],n,m,x,y,t = 0;
int get(){
	int x,y;
	scanf("%d.%d",&x,&y);
	return x * 100 + y;
}
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	n = get();
	scanf("%d",&m);
	memset(f,1,sizeof f);
	f[0] = 0;
	while (m--){
		x = get();
		scanf("%d",&y);
		t += y;
		for (int i = t;i >= y;i--){
			f[i] = min(f[i],f[i - y] + x);
			if (f[i] > n) f[i] = n + 1;
		}
	}
	int p = t;
	while (f[p] > n) p--;
	printf("%d",p);
}
