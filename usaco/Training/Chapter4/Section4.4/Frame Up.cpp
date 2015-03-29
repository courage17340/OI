/*
USER: courage2
LANG: C++
TASK: frameup
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct rec{
	int x,y;
	rec(int X = 0,int Y = 0):x(X),y(Y){}
};
int n,m,k,num,a[33][33],f[10010],l[33],r[33],u[33],d[33];
char s[33],ans[10010][33];
bool v[33] = {0};
int max(int a,int b){
	return a > b ? a : b;
}
int min(int a,int b){
	return a < b ? a : b;
}
void search(int p,char c){
	s[p - 1] = c;
	int x1,y1,x2,y2;
	x1 = u[c - 'A'];
	x2 = d[c - 'A'];
	y1 = l[c - 'A'];
	y2 = r[c - 'A'];
	for (int i = x1;i <= x2;i++) if (a[i][y1] != c && a[i][y1] != '*') return;
	for (int i = x1;i <= x2;i++) if (a[i][y2] != c && a[i][y2] != '*') return;
	for (int i = y1;i <= y2;i++) if (a[x1][i] != c && a[x1][i] != '*') return;
	for (int i = y1;i <= y2;i++) if (a[x2][i] != c && a[x2][i] != '*') return;
	if (p == k){
		num++;
		for (int i = 0;i < k;i++) ans[num][i] = s[k - 1 - i];
		ans[num][k] = 0;
		return;
	}
	v[c - 'A'] = 0;
	vector <rec> r;
	for (int i = x1;i <= x2;i++) if (a[i][y1] == c) r.push_back(rec(i,y1));
	for (int i = x1;i <= x2;i++) if (a[i][y2] == c) r.push_back(rec(i,y2));
	for (int i = y1 + 1;i < y2;i++) if (a[x1][i] == c) r.push_back(rec(x1,i));
	for (int i = y1 + 1;i < y2;i++) if (a[x2][i] == c) r.push_back(rec(x2,i));
	for (int i = 0;i < r.size();i++) a[r[i].x][r[i].y] = '*';
	for (int i = 0;i < 26;i++) if (v[i]) search(p + 1,i + 'A');
	for (int i = 0;i < r.size();i++) a[r[i].x][r[i].y] = c;
	v[c - 'A'] = 1;
}
bool cmp(int x,int y){
	return strcmp(ans[x],ans[y]) < 0;
}
int main(){
	freopen("frameup.in","r",stdin);
	freopen("frameup.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%s",s);
		for (int j = 1;j <= m;j++) a[i][j] = s[j - 1];
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) if (a[i][j] != '.') v[a[i][j] - 'A'] = 1;
	k = 0;
	for (int i = 0;i < 26;i++) k += v[i];
	num = 0;
	for (int s = 0;s < 26;s++) if (v[s]){
		int x1,y1,x2,y2;
		x1 = n;
		x2 = 1;
		y1 = m;
		y2 = 1;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++) if (a[i][j] == s + 'A'){
				x1 = min(x1,i);
				x2 = max(x2,i);
				y1 = min(y1,j);
				y2 = max(y2,j);
			}
		l[s] = y1;
		r[s] = y2;
		u[s] = x1;
		d[s] = x2;
	}
	for (int i = 0;i < 26;i++) if (v[i]) search(1,i + 'A');
	for (int i = 1;i <= num;i++) f[i] = i;
	sort(f + 1,f + num + 1,cmp);
	for (int i = 1;i <= num;i++) puts(ans[f[i]]);
}
