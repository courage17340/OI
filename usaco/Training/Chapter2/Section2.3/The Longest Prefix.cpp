/*
ID: courage2
TASK: prefix
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
char a[210][12],s[200010];
bool v[200110] = {0};
int n,m,l,t,b[210],ans = 0;
priority_queue <int, vector<int> ,greater<int> > q;
void read(){
	l = 0;
	int c;
	while (1){
		c = getchar();
		if (c == EOF) break;
		if ('A' <= c && c <= 'Z') s[l++] = c;
	}
	s[l] = 0;
}
bool cmp(int p,int q){
	if (b[q] + p > l) return 0;
	for (int i = 0;i < b[q];i++) if (s[p + i] != a[q][i]) return 0;
	return 1;
}
int main(){
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	n = 0;
	while (1){
		scanf("%s",a[++n]);
		b[n] = strlen(a[n]);
		if (a[n][0] == '.'){
			n--;
			break;
		}
	}
	read();
	q.push(0);
	while (!q.empty()){
		t = q.top();
		q.pop();
		for (int i = 1;i <= n;i++) if (!v[t + b[i]] && cmp(t,i)){
			v[t + b[i]] = 1;
			q.push(t + b[i]);
			if (ans < t + b[i]) ans = t + b[i];
		}
	}
	printf("%d\n",ans);
}
