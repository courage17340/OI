/*
USER: courage2
LANG: C++
TASK: camelot
*/
#include <cstdio>
#include <cstring>
struct rec{int x,y;};
rec a[10010],b[10010];
char s[3];
int n,m,k,x0,y0,x,y,z,X,Y,p,q,ans,d[31][31][31][31],f[8][2] = {{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};
int max(int a,int b){
	return a > b ? a : b;
}
int min(int a,int b){
	return a < b ? a : b;
}
int Abs(int x){
	return x > 0 ? x : -x;
}
int dk(int x1,int y1,int x2,int y2){
	return max(Abs(x1 - x2),Abs(y1 - y2));
}
int main(){
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(d,-1,sizeof d);
	for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++){
		d[i][j][i][j] = 0;
		p = q = 1;
		b[1].x = i;
		b[1].y = j;
		while (p <= q){
			for (int k = 0;k < 8;k++){
				x = b[p].x + f[k][0];
				y = b[p].y + f[k][1];
				if (x < 1 || x > n || y < 1 || y > m || d[i][j][x][y] >= 0) continue;
				d[i][j][x][y] = d[i][j][b[p].x][b[p].y] + 1;
				q++;
				b[q].x = x;
				b[q].y = y;
			}
			p++;
		}
	}
	scanf("%s%d",s,&y0);
	x0 = s[0] - 'A' + 1;
	k = 0;
	while (scanf("%s",s) != EOF){
		k++;
		scanf("%d",&a[k].y);
		a[k].x = s[0] - 'A' + 1;
	}
	if (k == 0){
		puts("0");
		return 0;
	}
	ans = 1e9;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++){
			z = 0;
			bool flag = 0;
			for (int p = 1;p <= k;p++){
				x = d[i][j][a[p].x][a[p].y];
				if (x < 0){
					flag = 1;
					break;
				}
				z += x;
			}
			if (flag) continue;
			if (z >= ans) continue;
			for (int r = 1;r <= k;r++){
				x = z - d[i][j][a[r].x][a[r].y];
				for (int p = 1;p <= n;p++)
					for (int q = 1;q <= m;q++){
						X = d[a[r].x][a[r].y][p][q];
						Y = d[p][q][i][j];
						if (X < 0 || Y < 0) continue;
						y = x + dk(x0,y0,p,q) + X + Y;
						ans = min(ans,y);
					}
			}
		}
	printf("%d\n",ans);
}
