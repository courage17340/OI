/*
USER: courage2
LANG: C++
TASK: tour
*/
#include <cstdio>
#include <map>
#include <string>
using namespace std;
map <string,int> dic;
char s[30];
string t;
int n,m,x,y,ans,f[110][110] = {{0}};
bool a[110][110] = {{0}};
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%s",s);
		t = s;
		dic.insert(make_pair(t,i));
	}
	while (m--){
		scanf("%s",s);
		t = s;
		x = dic.find(t)->second;
		scanf("%s",s);
		t = s;
		y = dic.find(t)->second;
		a[x][y] = a[y][x] = 1;
	}
	f[1][1] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			for (int k = 1;k < j;k++) if (f[i][k] && a[k][j]){
				f[i][j] = max(f[i][j],f[i][k] + 1);
				f[j][i] = f[i][j];
			}
	ans = 0;
	for (int i = 1;i < n;i++) if (a[i][n]) ans = max(ans,f[i][n]);
	if (!ans) ans = 1;
	printf("%d\n",ans);
}
