#include <cstdio>
int f[1080010] = {0},n,t,x,y,x1,y1;
int max(int a,int b){return a > b ? a : b;}
int main(){
	scanf("%d%d",&n,&t);
	while (n--){
		scanf("%d%d%d%d",&x,&y,&x1,&y1);
		for (int i = t;i >= 0;i--){
			if (i >= y) f[i] = max(f[i],f[i - y] + x);
			if (i >= y1) f[i] = max(f[i],f[i - y1] + x1);
		}
	}
	printf("%d\n",f[t]);
}
