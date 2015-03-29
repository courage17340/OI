#include <cstdio>
char s[40];
int a[40][40][40],p,q,l,r,c,x,y,z,x0,x1,y0,y1,z0,z1,f[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct rec{int x,y,z,k;};
rec b[30000];
int main(){
	while (1){
		scanf("%d%d%d",&l,&r,&c);
		if (l + r + c == 0) break;
		for (int i = 1;i <= l;i++)
			for (int j = 1;j <= r;j++){
				scanf("%s",s);
				for (int k = 1;k <= c;k++) a[i][j][k] = (s[k - 1] == '#' ? 1 : 0);
				for (int k = 0;k < c;k++) if (s[k] == 'S'){
					x0 = i;
					y0 = j;
					z0 = k + 1;
				}else if (s[k] == 'E'){
					x1 = i;
					y1 = j;
					z1 = k + 1;
				}
			}
		p = q = 1;
		b[1].x = x0;
		b[1].y = y0;
		b[1].z = z0;
		a[x0][y0][z0] = 1;
		while (p <= q){
			if (b[p].x == x1 && b[p].y == y1 && b[p].z == z1) break;
			for (int k = 0;k < 6;k++){
				x = b[p].x + f[k][0];
				y = b[p].y + f[k][1];
				z = b[p].z + f[k][2];
				if (1 <= x && x <= l && 1 <= y && y <= r && 1 <= z && z <= c && !a[x][y][z]){
					a[x][y][z] = 1;
					q++;
					b[q].x = x;
					b[q].y = y;
					b[q].z = z;
					b[q].k = b[p].k + 1;
				}
			}
			p++;
		}
		if (a[x][y][z]) printf("Escaped in %d minute(s).\n",b[p].k);else printf("Trapped!\n");
	}
}