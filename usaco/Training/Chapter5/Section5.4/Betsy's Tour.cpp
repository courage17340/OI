/*
USER: courage2
LANG: C++
TASK: betsy
*/
#include <cstdio>
int n,ans = 0,d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool v[8][8] = {{0}};
bool block(int x,int y){
	return x < 1 || x > n || y < 1 || y > n || v[x][y];
}
bool empty(int x,int y){
	return x >= 1 && x <= n && y >= 1 && y <= n && !v[x][y];
}
bool three(int x,int y){
	if (x < 1 || x > n || y < 1 || y > n || v[x][y]) return 0;
	if (x == n && y == 1) return 0;
	int tmp = 0;
	for (int i = 0;i < 4;i++) tmp += block(x + d[i][0],y + d[i][1]);
	return tmp >= 3;
}
void search(int step,int x,int y,int dx,int dy){
	if (step == n * n && x == n && y == 1){
		ans++;
		return;
	}
	if (step < n * n && x == n && y == 1) return;
	if (block(x + dx,y + dy) && empty(x - dy,y + dx) && empty(x + dy,y - dx)) return;
	int tmp = 0,P;
	for (int k = 0;k < 4;k++) if (three(x + d[k][0],y + d[k][1])){
		tmp++;
		P = k;
	}
	if (tmp > 1) return;
	if (tmp == 1){
		v[x + d[P][0]][y + d[P][1]] = 1;
		search(step + 1,x + d[P][0],y + d[P][1],d[P][0],d[P][1]);
		v[x + d[P][0]][y + d[P][1]] = 0;
		return;
	}
	int p,q;
	for (int k = 0;k < 4;k++){
		p = x + d[k][0];
		q = y + d[k][1];
		if (empty(p,q)){
			v[p][q] = 1;
			search(step + 1,p,q,d[k][0],d[k][1]);
			v[p][q] = 0;
		}
	}
}
int main(){
	freopen("betsy.in","r",stdin);
	freopen("betsy.out","w",stdout);
	scanf("%d",&n);
	v[1][1] = 1;
	search(1,1,1,0,1);
	printf("%d\n",ans);
}
