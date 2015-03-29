#include<cstdio>
int x,y,ans = 0;
int gcd(int x,int y){
	if (y == 0) return x;
	return (gcd(y,x % y));
}
int main(){
	scanf("%d%d",&x,&y);
	if (y % x){
		printf("0\n");
		return 0;
	}
	y /= x;
	for (int i = 1;i * i <= y;i++) if (y%i==0 && gcd(i,y/i)==1) ans++;
	printf("%d\n",ans);
}
