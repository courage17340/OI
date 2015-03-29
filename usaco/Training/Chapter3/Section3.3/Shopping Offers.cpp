/*
USER: courage2
LANG: C++
TASK: shopping
*/
#include <cstdio>
#include <cstring>
struct rec{
	int n,x[6],y[6],c;
};
rec a[110];
struct off{
	int x[6],c;
};
off b[110];
struct pur{
	int x,y,z;
};
pur c[6];
int n,m,x,y,z,f[6][6][6][6][6] = {{{{{0}}}}},g[1000] = {0};
char s[3];
int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d",&m);
	for (int i = 1;i <= m;i++){
		scanf("%d",&a[i].n);
		for (int j = 1;j <= a[i].n;j++) scanf("%d%d",&a[i].x[j],&a[i].y[j]);
		scanf("%d",&a[i].c);
	}
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].z);
		g[c[i].x] = i;
	}
	for (int i = n + 1;i <= 5;i++) c[i].x = c[i].y = c[i].z = 0;
	for (int i = 0;i <= c[1].y;i++)
		for (int j = 0;j <= c[2].y;j++)
			for (int k = 0;k <= c[3].y;k++)
				for (int p = 0;p <= c[4].y;p++)
					for (int q = 0;q <= c[5].y;q++) f[i][j][k][p][q] = c[1].z * i + c[2].z * j + c[3].z * k + c[4].z * p + c[5].z * q;
	n = 0;
	for (int i = 1;i <= m;i++){
		n++;
		b[n].c = a[i].c;
		bool flag = 0;
		for (int j = 1;j <= a[i].n;j++) if (!g[a[i].x[j]]){
			flag = 1;
			break;
		}else{
			b[n].x[g[a[i].x[j]]] = a[i].y[j];
		}
		if (flag){
			n--;
			continue;
		}
	}
	for (int t = 1;t <= n;t++)
		for (int i = b[t].x[1];i <= c[1].y;i++)
			for (int j = b[t].x[2];j <= c[2].y;j++)
				for (int k = b[t].x[3];k <= c[3].y;k++)
					for (int p = b[t].x[4];p <= c[4].y;p++)
						for (int q = b[t].x[5];q <= c[5].y;q++)
							f[i][j][k][p][q] = min(f[i][j][k][p][q],f[i - b[t].x[1]][j - b[t].x[2]][k - b[t].x[3]][p - b[t].x[4]][q - b[t].x[5]] + b[t].c);
	printf("%d\n",f[c[1].y][c[2].y][c[3].y][c[4].y][c[5].y]);
}
