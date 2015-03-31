#include<cstdio>
char s[10][10];
int t,x,y,p,q,ans;
bool f;
inline int abs(int x){
	return (x > 0 ? x : -x);
}
void no(){
	printf("NO\n");
}
void yes(){
	printf("YES\n");
}
int main(){
	scanf("%d",&t);
	while (t--){
		for (int i = 0;i < 8;i++) scanf("%s",s[i]);
		x = y = -1;
		for (int i = 0;i < 8;i++)
			for (int j = 0;j < 8;j++) if (s[i][j] == 'K')
				if (x == -1){
					x = i;
					y = j;
				}else{
					p = i;
					q = j;
				}
		if (abs(p - x) & 3 || abs(q - y) & 3){
			no();
			continue;
		}
		f = 0;
		for (int i = 0;i < 8;i++)
			for (int j = 0;j < 8;j++) if ((s[i][j] == '.' || s[i][j] == '#') && (abs(i + j - p - q) & 3) == 0 && (abs(i - p) & 1) == 0 && (abs(j - q) & 1) == 0)
				f = 1;
		if (f) yes();else no();
	}
}
