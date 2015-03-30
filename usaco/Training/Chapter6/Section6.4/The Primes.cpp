/*
USER: courage2
LANG: C++
TASK: prime3
*/
#include <cstdio>
#include <algorithm>
bool f[100010] = {0};
struct rec{
	int v[6][6];
	void show(){
		for (int i = 1;i <= 5;i++){
			for (int j = 1;j <= 5;j++) printf("%d",v[i][j]);
			printf("\n");
		}
	}
};
rec ans[1010];
int n,x0,p,q,a[6][6],m = 0;
int count(int x){
	int y = 0;
	while (x){
		y += x % 10;
		x /= 10;
	}
	return y;
}
int Max(int a,int b){
	return a > b ? a : b;
}
bool check(int k,int x = 0){
	int y = 0;
	if (k == 1){
		for (int i = 1;i <= 5;i++) if (a[x][i] < 0 || a[x][i] > 9) return 0;
		for (int i = 1;i <= 5;i++) y = y * 10 + a[x][i];
		return !f[y];
	}else if (k == 2){
		for (int i = 1;i <= 5;i++) if (a[i][x] < 0 || a[i][x] > 9) return 0;
		for (int i = 1;i <= 5;i++) y = y * 10 + a[i][x];
		return !f[y];
	}else if (k == 3){
		for (int i = 1;i <= 5;i++) if (a[i][i] < 0 || a[i][i] > 9) return 0;
		for (int i = 1;i <= 5;i++) y = y * 10 + a[i][i];
		return !f[y];
	}else{
		for (int i = 1;i <= 5;i++) if (a[6 - i][i] < 0 || a[6 - i][i] > 9) return 0;
		for (int i = 1;i <= 5;i++) y = y * 10 + a[6 - i][i];
		return !f[y];
	}
}
void search(int x,int y,int z){
	a[x][y] = z;
	if (z == 0 && (x == 1 || y == 1)) return;
	if ((z == 5 || z % 2 == 0) && (x == 5 || y == 5)) return;
	if (x == 4 && y == 4 && !check(3)) return;
	if (x == 2 && y == 4 && !check(4)) return;
	if (x == 1 && y == 4 && !check(1,1)) return;
	if (x == 2 && y == 3 && !check(1,2)) return;
	if (x == 4 && y == 1 && !check(2,1)) return;
	if (x == 4 && y == 5 && !check(2,5)) return;
	if (x == 4 && y == 3 && !check(1,4)) return;
	if (x == 5 && y == 3 && !check(2,3)) return;
	if (x == 5 && y == 4 && !check(1,5)) return;
	if (x == 3 && y == 2 && !check(2,2)) return;
	if (x == 3 && y == 4 && (!check(1,3) || !check(2,4))) return;
	
	if (x == 3 && y == 4){
		m++;
		for (int i = 1;i <= 5;i++) for (int j = 1;j <= 5;j++) ans[m].v[i][j] = a[i][j];
		return;
	}
	int t = n;
	if (x == y){
		if (x == 1){
			t -= a[1][1];
			for (int i = 1;i <= 9 && i <= t;i += 2) search(5,5,i);
		}else if (x == 5){
			t -= (a[1][1] + a[5][5]);
			for (int i = 0;i <= 9 && i <= t;i++) search(2,2,i);
		}else if (x == 2){
			t -= (a[1][1] + a[2][2] + a[5][5]);
			for (int i = 0;i <= 9 && i <= t;i++) search(3,3,i);
		}else if (x == 3){
			t -= (a[1][1] + a[2][2] + a[3][3] + a[5][5]);
			search(4,4,t);
		}else{
			t -= Max(a[1][1],a[5][5]);
			for (int i = 1;i <= 9 && i < t;i += 2) search(5,1,i);
		}
	}else if (x == 5 && y == 1){
		t -= Max(Max(a[5][1] + a[3][3],a[1][1]),a[5][5]);
		for (int i = 1;i <= 9 && i < t;i += 2) search(1,5,i);
	}else if (x == 1 && y == 5){
		t -= Max(Max(a[5][1] + a[3][3] + a[1][5],a[2][2]),a[4][4]);
		for (int i = 0;i <= 9 && i <= t;i++) search(4,2,i);
	}else if (x == 4 && y == 2){
		t -= (a[5][1] + a[4][2] + a[3][3] + a[1][5]);
		search(2,4,t);
	}else if (x == 2 && y == 4){
		t -= Max(a[1][1] + a[1][5],a[2][2] + a[4][2]);
		for (int i = 1;i <= 9 && i < t;i++) search(1,2,i);
	}else if (x == 1 && y == 2){
		t -= Max(a[1][1] + a[1][2] + a[1][5],a[3][3]);
		for (int i = 1;i <= 9 && i < t;i++) search(1,3,i);
	}else if (x == 1 && y == 3){
		t -= (a[1][1] + a[1][2] + a[1][3] + a[1][5]);
		if (t > 0 && t + a[2][4] + a[4][4] < n) search(1,4,t);
	}else if (x == 1 && y == 4){
		t -= Max(a[1][1] + a[5][1],a[2][2] + a[2][4]);
		for (int i = 1;i <= 9 && i < t;i++) search(2,1,i);
	}else if (x == 2 && y == 1){
		t -= Max(a[2][1] + a[2][2] + a[2][4],a[1][5] + a[5][5]);
		for (int i = 1;i <= 9 && i <= t;i += 2) search(2,5,i);
	}else if (x == 2 && y == 5){
		t -= (a[2][1] + a[2][2] + a[2][4] + a[2][5]);
		if (t + a[1][3] + a[3][3] < n) search(2,3,t);
	}else if (x == 2 && y == 3){
		t -= Max(a[1][1] + a[2][1] + a[5][1],a[3][3]);
		for (int i = 1;i <= 9 && i < t;i++) search(3,1,i);
	}else if (x == 3 && y == 1){
		t -= (a[1][1] + a[2][1] + a[3][1] + a[5][1]);
		if (t + a[4][2] + a[4][4] < n) search(4,1,t);
	}else if (x == 4 && y == 1){
		t -= Max(a[3][1] + a[3][3],a[1][5] + a[2][5] + a[5][5]);
		for (int i = 1;i <= 9 && i <= t;i += 2) search(3,5,i);
	}else if (x == 3 && y == 5){
		t -= (a[1][5] + a[2][5] + a[3][5] + a[5][5]);
		if (t + a[4][1] + a[4][2] + a[4][4] <= n) search(4,5,t);
	}else if (x == 4 && y == 5){
		t -= (a[4][1] + a[4][2] + a[4][4] + a[4][5]);
		search(4,3,t);
	}else if (x == 4 && y == 3){
		t -= (a[1][3] + a[2][3] + a[3][3] + a[4][3]);
		search(5,3,t);
	}else if (x == 5 && y == 3){
		t -= Max(a[5][1] + a[5][3] + a[5][5],a[1][2] + a[2][2] + a[4][2]);
		for (int i = 1;i <= 9 && i <= t;i += 2) search(5,2,i);
	}else if (x == 5 && y == 2){
		t -= (a[5][1] + a[5][2] + a[5][3] + a[5][5]);
		search(5,4,t);
	}else if (x == 5 && y == 4){
		t -= (a[1][2] + a[2][2] + a[4][2] + a[5][2]);
		search(3,2,t);
	}else{
		t -= (a[3][1] + a[3][2] + a[3][3] + a[3][5]);
		search(3,4,t);
	}
}
bool cmp(rec a,rec b){
	for (int i = 1;i <= 5;i++)
		for (int j = 1;j <= 5;j++) if (a.v[i][j] != b.v[i][j]) return a.v[i][j] < b.v[i][j];
	return 0;
}
int main(){
	freopen("prime3.in","r",stdin);
	freopen("prime3.out","w",stdout);
	scanf("%d%d",&n,&x0);
	p = 2;
	while (p * p <= 100000){
		while (f[p]) p++;
		for (int j = p * 2;j <= 100000;j += p) f[j] = 1;
		p++;
	}
	for (int i = 2;i < 10000;i++) f[i] = 1;
	for (int i = 10000;i <= 99999;i++) if (!f[i] && count(i) != n) f[i] = 1;
	
	search(1,1,x0);
	if (!m){
		puts("NONE");
		return 0;
	}
	std::sort(ans + 1,ans + m + 1,cmp);
	ans[1].show();
	for (int i = 2;i <= m;i++){
		printf("\n");
		ans[i].show();
	}
}
