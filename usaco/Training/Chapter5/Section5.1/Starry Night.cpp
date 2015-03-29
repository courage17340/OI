/*
USER: courage2
LANG: C++
TASK: starry
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char s[110];
struct point{
	int x,y;
	point(int X = 0,int Y = 0):x(X),y(Y){}
	point(const point &a){
		x = a.x;
		y = a.y;
	}
};
vector <point> c[30],t;
point tmp;
int a[110][110],b[110][110],p,q,k,n,m,x,y,num,d[8][2][2] = {{{1,0},{0,1}},{{1,0},{0,-1}},{{-1,0},{0,1}},{{-1,0},{0,-1}},
{{0,1},{1,0}},{{0,1},{-1,0}},{{0,-1},{1,0}},{{0,-1},{-1,0}}};
bool cmp(point a,point b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool check(const vector<point> &a,const vector<point> &b){
	if (a.size() != b.size()) return 0;
	vector <point> c;
	bool flag;
	point t;
	int n = a.size();
	for (int i = 0;i < 8;i++){
		flag = 1;
		c.clear();
		for (int j = 0;j < n;j++){
			t.x = a[j].x * d[i][0][0] + a[j].y * d[i][0][1];
			t.y = a[j].x * d[i][1][0] + a[j].y * d[i][1][1];
			c.push_back(t);
		}
		sort(c.begin(),c.end(),cmp);
		int dx = c[0].x - b[0].x;
		int dy = c[0].y - b[0].y;
		for (int j = 1;j < n;j++) if (c[j].x - b[j].x != dx || c[j].y - b[j].y != dy){
			flag = 0;
			break;
		}
		if (flag) return 1;
	}
	return 0;
}
int main(){
	freopen("starry.in","r",stdin);

	freopen("starry.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i = 1;i <= n;i++){
		scanf("%s",s);
		for (int j = 1;j <= m;j++) a[i][j] = s[j - 1] - '0';
	}
	num = 0;
	for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) b[i][j] = '0';
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) if (a[i][j]){
			a[i][j] = 0;
			t.clear();
			t.push_back(point(i,j));
			p = q = 0;
			while (p <= q){
				for (int dx = -1;dx <= 1;dx++)
					for (int dy = -1;dy <= 1;dy++) if (dx || dy){
						x = t[p].x + dx;
						y = t[p].y + dy;
						if (x < 1 || x > n || y < 1 || y > m || !a[x][y]) continue;
						q++;
						t.push_back(point(x,y));
						a[x][y] = 0;
					}
				p++;
			}
			k = -1;
			for (int r = 1;r <= num;r++) if (check(t,c[r])){
				k = r + 'a' - 1;
				break;
			}
			if (k < 0){
				sort(t.begin(),t.end(),cmp);
				c[++num] = t;
				k = num + 'a' - 1;
			}
			for (int r = 0;r < t.size();r++) b[t[r].x][t[r].y] = k;
		}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++) putchar(b[i][j]);
		putchar('\n');
	}
}
