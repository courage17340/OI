/*
ID: courage2
TASK: ttwo
LANG: C++
*/
#include <cstdio>
int a[14][14],x,y,k,x1,y1,k1,t,d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
char s[14];
bool v[11][11][11][11][5][5] = {{{{{{0}}}}}};
bool check(int x0,int y0,int k){
	int x = x0 + d[k][0],y = y0 + d[k][1];
	return (0 < x && x < 11 && 0 < y && y < 11 && !a[x][y]);
}
int main(){
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	for (int i = 1;i <= 10;i++){
		scanf("%s",s);
		for (int j = 1;j <= 10;j++) a[i][j] = (s[j - 1] == '*');
		for (int j = 0;j < 10;j++) if (s[j] == 'F'){
			x = i;
			y = j + 1;
			k = 0;
		}else if (s[j] == 'C'){
			x1 = i;
			y1 = j + 1;
			k1 = 0;
		}
	}
	t = 0;
	while (1){
		t++;
		if (check(x,y,k)){
			x += d[k][0];
			y += d[k][1];
		}else{
			k++;
			if (k > 3) k = 0;
		}
		if (check(x1,y1,k1)){
			x1 += d[k1][0];
			y1 += d[k1][1];
		}else{
			k1++;
			if (k1 > 3) k1 = 0;
		}
		if (x == x1 && y == y1) break;
		if (v[x][y][x1][y1][k][k1]){
			t = 0;
			break;
		}
		v[x][y][x1][y1][k][k1] = 1;
	}
	printf("%d\n",t);
}
