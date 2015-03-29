/*
USER: courage2
LANG: C++
TASK: snail
*/
#include <cstdio>
int n,m,x,y,ans,a[210][210] = {{0}},d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char c;
void search(int x,int y,int z){
	if (z > ans) ans = z;
	int tx,ty,xx,yy,tmp;
	for (int k = 0;k < 4;k++){
		tmp = 0;
		tx = x;
		ty = y;
		while (1){
			xx = tx + d[k][0];
			yy = ty + d[k][1];
			if (xx < 1 || xx > n || yy < 1 || yy > n || a[xx][yy]) break;
			tx = xx;
			ty = yy;
			tmp++;
			a[tx][ty] = 1;
		}
		if (tx != x || ty != y){
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && a[xx][yy] == 1){
				if (ans < z + tmp) ans = z + tmp;
			}else search(tx,ty,z + tmp);
			xx = x;
			yy = y;
			do{
				xx += d[k][0];
				yy += d[k][1];
				a[xx][yy] = 0;
			}while (xx != tx || yy != ty);
		}
	}
}
int main(){
	freopen("snail.in","r",stdin);
	freopen("snail.out","w",stdout);
	scanf("%d%d%*c",&n,&m);
	for (int i = 1;i <= m;i++){
		scanf("%c%d%*c",&c,&x);
		a[x][c - 'A' + 1] = -1;
	}
	ans = 0;
	a[1][1] = 1;
	search(1,1,1);
	printf("%d\n",ans);
}
