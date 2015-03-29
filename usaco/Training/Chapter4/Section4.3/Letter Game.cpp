/*
USER: courage2
LANG: C++
TASK: lgame
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
char s[10],t[10],key[30] = "25441655176352357212466757";
struct node{
	bool flag;
	node *c[26];
};
node *root,*p,pool[80010];
node *get(){
	static int x = 0;
	for (int i = 0;i < 26;i++) pool[x].c[i] = NULL;
	pool[x].flag = 0;
	return &pool[x++];
}
struct rec{
	char s[10],t[10];
	rec(){
		s[0] = t[0] = 0;
	}
	bool operator <(const rec &a){
		return (strcmp(s,a.s) < 0 || (strcmp(s,a.s) == 0 && strcmp(t,a.t) < 0));
	}
	bool operator ==(const rec &a){
		return strcmp(s,a.s) == 0 && strcmp(t,a.t) == 0;
	}
};
bool cmp(rec a,rec b){
	return a < b;
}
rec ans[80010];
int n,m,l,v[30],a[30],mx,x,y;
bool f[10] = {0};
bool yes(int a[],int l,int r){
	node *p = root;
	for (int i = l;i <= r;i++){
		if (p->c[a[i] - 'a'] == NULL) return 0;
		p = p->c[a[i] - 'a'];
	}
	return p->flag;
}
int value(const char *s){
	int l = strlen(s);
	int ret = 0;
	for (int i = 0;i < l;i++) ret += v[s[i] - 'a'];
	return ret;
}
void test(const rec &a){
	if (a.t[0] != 0 && strcmp(a.s,a.t) > 0) return;
	int x = value(a.s) + value(a.t);
	if (x < mx) return;
	if (x == mx) ans[++m] = a;
	if (x > mx){
		mx = x;
		ans[m = 1] = a;
	}
}
void check(){
	rec q;
	for (int i = 0;i < l;i++) if (yes(a,0,i)){
		q.t[0] = 0;
		for (int j = 0;j <= i;j++) q.s[j] = a[j];
		q.s[i + 1] = 0;
		test(q);
		for (int j = i + 1;j < l;j++) if (yes(a,i + 1,j)){
			for (int k = i + 1;k <= j;k++) q.t[k - i - 1] = a[k];
			q.t[j - i] = 0;
			test(q);
		}
	}
}
void search(int k,int x){
	a[k] = s[x];
	if (k == l - 1){
		check();
		return;
	}
	f[x] = 1;
	for (int i = 0;i < l;i++) if (!f[i]) search(k + 1,i);
	f[x] = 0;
}
int main(){
	freopen("lgame.in","r",stdin);
	scanf("%s",t);
	freopen("lgame.out","w",stdout);
	freopen("lgame.dict","r",stdin);
	root = get();
	for (int i = 0;i < 26;i++) v[i] = key[i] - '0';
	while (1){
		scanf("%s",s);
		if (s[0] == '.') break;
		l = strlen(s);
		p = root;
		for (int i = 0;i < l;i++){
			if (p->c[s[i] - 'a'] == NULL) p->c[s[i] - 'a'] = get();
			p = p->c[s[i] - 'a'];
			if (i == l - 1) p->flag = 1;
		}
	}
	strcpy(s,t);
	l = strlen(s);
	m = 0;
	mx = 0;
	for (int i = 0;i < l;i++) search(0,i);
	std::sort(ans + 1,ans + m + 1,cmp);
	x = 1;
	printf("%d\n",mx);
	while (x <= m){
		y = x;
		while (y < m && ans[x] == ans[y + 1]) y++;
		printf("%s",ans[x].s);
		if (ans[x].t[0] != 0) printf(" %s",ans[x].t);
		printf("\n");
		x = y + 1;
	}
}
