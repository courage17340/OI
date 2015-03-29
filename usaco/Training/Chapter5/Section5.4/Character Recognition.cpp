/*
USER: courage2
LANG: C++
TASK: charrec
*/
#include <cstdio>
#include <cstring>
char s[1310][22],t[550][22],font[33] = " abcdefghijklmnopqrstuvwxyz";
int d[1310][550],n,m,f[1310],g[1310][3][27],ans[1310],ope[1310];
int differ(const char *s,const char *t){
	int ret = 0;
	for (int i = 0;i < 20;i++) ret += (s[i] != t[i]);
	return ret;
}
void work(int x){
	if (x > n) return;
	printf("%c",ans[x]);
	work(ope[x]);
}
int main(){
	freopen("font.in","r",stdin);
	scanf("%d",&m);
	for (int i = 1;i <= m;i++) scanf("%s",t[i]);
	freopen("charrec.in","r",stdin);
	freopen("charrec.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%s",s[i]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) d[i][j] = differ(s[i],t[j]);
	memset(g,1,sizeof g);
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= 2;j++) if (i + j + 18 <= n)
			for (int k = 0;k <= 26;k++){
				int start = k * 20 + 1,end = k * 20 + 20,tmp;
				if (j == 1){
					tmp = 0;
					for (int l = start;l <= end;l++) tmp += d[l - start + i][l];
				}else if (j == 0){
					tmp = 1e9;
					int x;
					for (int l = start;l <= end;l++){
						x = 0;
						for (int r = start;r < l;r++) x += d[r - start + i][r];
						for (int r = l + 1;r <= end;r++) x += d[r - start + i - 1][r];
						if (tmp > x) tmp = x;
					}
				}else{
					tmp = 1e9;
					int x;
					for (int l = start;l <= end;l++){
						x = 0;
						for (int r = start;r <= l;r++) x += d[r - start + i][r];
						for (int r = l;r <= end;r++) x += d[r - start + i + 1][r];
						if (tmp > x) tmp = x;
					}
				}
				g[i][j][k] = tmp;
			}
	memset(f,1,sizeof f);
	f[n + 1] = 0;
	for (int i = n - 18;i >= 1;i--){
		for (int j = i + 19;j <= i + 21;j++)
			for (int k = 0;k <= 26;k++) if (f[i] > f[j] + g[i][j - i - 19][k]){
				f[i] = f[j] + g[i][j - i - 19][k];
				ope[i] = j;
				ans[i] = font[k];
			}
	}
	work(1);
	printf("\n");
}
