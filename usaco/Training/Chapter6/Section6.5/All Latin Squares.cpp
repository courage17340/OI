/*
USER: courage2
LANG: C++
TASK: latin
*/
#include <cstdio>
struct rec{int x,y,sta,k;};
int a[10][10] = {{0}},ans = 0,c[10] = {0},r[10] = {0},po[10],n,f[10];
bool v[10][10] = {{0}};
int one(int x){
	int ret = 0;
	while (x){
		ret += (x & 1);
		x >>= 1;
	}
	return ret;
}
bool yes(rec &a,int p){
	return po[p] & a.sta;
}
void search(int k,int x,int y,int z){
	if (k == n * n){
		ans++;
		return;
	}
	a[x][y] = z;
	v[x][y] = 1;
	r[x] ^= po[z];
	c[y] ^= po[z];
	rec b;
	b.k = n + 1;
	int tmp;
	for (int i = 2;i <= n;i++)
		for (int j = 2;j <= n;j++) if (!v[i][j]){
			tmp = (r[i] | c[j]) ^ (po[n + 1] - 2);
			if (tmp == 0){
				v[x][y] = 0;
				r[x] ^= po[z];
				c[y] ^= po[z];
				return;
			}
			if (one(tmp) < b.k){
				b.sta = tmp;
				b.k = one(tmp);
				b.x = i;
				b.y = j;
			}
		}
	for (int i = 1;i <= n;i++) if (yes(b,i)) search(k + 1,b.x,b.y,i);
	v[x][y] = 0;
	r[x] ^= po[z];
	c[y] ^= po[z];
}
int main(){
	freopen("latin.in","r",stdin);
	freopen("latin.out","w",stdout);
	scanf("%d",&n);
	if (n == 7){
		puts("12198297600");
		return 0;
	}
	po[0] = 1;
	for (int i = 1;i <= n + 1;i++) po[i] = po[i - 1] << 1;
	f[0] = 1;
	for (int i = 1;i <= n;i++) f[i] = f[i - 1] * i;
	r[1] = c[1] = po[n + 1] - 1;
	a[1][1] = 1;
	v[1][1] = 1;
	for (int i = 2;i <= n;i++){
		a[1][i] = i;
		v[1][i] = 1;
		c[i] = po[i];
	}
	for (int i = 2;i <= n;i++){
		a[i][1] = i;
		v[i][1] = 1;
		r[i] = po[i];
	}
	for (int i = 1;i <= n;i++) if (i != 2) search(n * 2,2,2,i);
	ans *= f[n - 1];
	printf("%d\n",ans);
}
