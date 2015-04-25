#include <cstdio>
#include <cstring>
int t,y,m,d,y1,m1,d1;
char s[12],mon[13][12] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
int getMon(char *s){
	int ret;
	for (int i = 1;i <= 12;++i)
		if (strcmp(s,mon[i]) == 0){
			ret = i;
			break;
		}
	return ret;
}
int num(int y){
	if (y < 2000) return 0;
	int ret = (y - 2000) / 4 + 1;
	int h = (y - 2000) / 100;
	ret -= h;
	ret += h / 4;
	return ret;
}
int calc(int a,int b){
	return num(b) - num(a - 1);
}
int main(){
	scanf("%d",&t);
	for (int T = 1;T <= t;++T){
		scanf("%s%d,%d",s,&d,&y);
		m = getMon(s);
		scanf("%s%d,%d",s,&d1,&y1);
		m1 = getMon(s);
		if (m > 2) ++y;
		if (m1 < 2 || (m1 == 2 && d1 < 29)) --y1;
		printf("Case #%d: %d\n",T,calc(y,y1));
	}
}
