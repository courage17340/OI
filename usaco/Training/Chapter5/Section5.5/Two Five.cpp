/*
USER: courage2
LANG: C++
TASK: twofive
*/
#include <cstdio>
#include <cstring>
int k,n,m[6][6],f[6][6][6][6][6],row[6],col[6],ans;
bool u[33],v[33];
char s[33],t[33];
int work(int a,int b,int c,int d,int e,int k){
	int &tmp = f[a][b][c][d][e];
	if (tmp > -1) return tmp;
	if (a < b || b < c || c < d || d < e) return tmp = 0;
	if (k == 25) return tmp = 1;
	if (v[k]) return tmp = work(a,b,c,d,e,k + 1);
	tmp = 0;
	if (a < 5 && k > col[1]) tmp += work(a + 1,b,c,d,e,k + 1);
	if (b < 5 && a > b && k > col[2] && k > row[b + 1]) tmp += work(a,b + 1,c,d,e,k + 1);
	if (c < 5 && b > c && k > col[3] && k > row[c + 1]) tmp += work(a,b,c + 1,d,e,k + 1);
	if (d < 5 && c > d && k > col[4] && k > row[d + 1]) tmp += work(a,b,c,d + 1,e,k + 1);
	if (e < 5 && d > e && k > col[5] && k > row[e + 1]) tmp += work(a,b,c,d,e + 1,k + 1);
	return tmp;
}
int fun(const char *s){
	int l = strlen(s);
	memset(f,-1,sizeof f);
	memset(row,0,sizeof row);
	memset(col,0,sizeof col);
	memset(v,0,sizeof v);
	memset(m,0,sizeof m);
	int x,y;
	for (int i = 0;i < l;i++){
		x = i / 5 + 1;
		y = i % 5 + 1;
		m[x][y] = s[i];
		if (s[i] - 'A' + 1 > row[x]) row[x] = s[i] - 'A' + 1;
		if (s[i] - 'A' + 1 > col[y]) col[y] = s[i] - 'A' + 1;
		v[s[i] - 'A' + 1] = 1;
	}
	for (int i = 1;i <= 5;i++)
		for (int j = 1;j <= 5;j++) if (m[i][j] && (m[i][j] < m[i - 1][j] || m[i][j] < m[i][j - 1])) return 0;
	f[5][5][5][5][5] = 1;
	int a[6] = {0},p;
	for (int i = 1;i <= 5;i++){
		p = 0;
		while (p < 5 && m[p + 1][i]) p++;
		a[i] = p;
	}
	return work(a[1],a[2],a[3],a[4],a[5],1);
}
void search(int k,int c){
	t[k] = c;
	t[k + 1] = 0;
	if (strcmp(t,s) > 0) return;
	bool flag = 1;
	for (int i = 0;i <= k;i++) if (s[i] != t[i]) flag = 0;
	if (!flag){
		ans += fun(t);
		return;
	}
	u[c - 'A' + 1] = 1;
	for (int i = 1;i <= 25;i++) if (!u[i]) search(k + 1,i - 1 + 'A');
	u[c - 'A' + 1] = 0;
}
void work_n(int k){
	memset(u,0,sizeof u);
	int tmp;
	t[0] = 'A';
	u[1] = 1;
	for (int i = 1;i < 25;i++){
		for (int j = 1;j <= 25;j++) if (!u[j]){
			t[i] = j - 1 + 'A';
			t[i + 1] = 0;
			tmp = fun(t);
			if (tmp < k){
				k -= tmp;
			}else break;
		}
		u[t[i] - 'A' + 1] = 1;
	}
	puts(t);
}
void work_w(){
	memset(u,0,sizeof u);
	ans = 0;
	search(0,'A');
	printf("%d\n",ans + 1);
}
int main(){
	freopen("twofive.in","r",stdin);
	freopen("twofive.out","w",stdout);
	scanf("%s",s);
	if (s[0] == 'N'){
		scanf("%d",&k);
		work_n(k);
	}else{
		scanf("%s",s);
		work_w();
	}
}
