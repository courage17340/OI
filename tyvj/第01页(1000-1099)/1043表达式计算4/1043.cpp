#include <cstdio>
#include <cstring>
typedef long long ll;
char s[210],t[110],c;
int p,q,r,l,x;
ll stack[110];
struct node{
	int t,k;
	char c;
	ll v;
};
node a[110],b[110],f[110];
bool flag;
ll pow(ll a,ll b){
	if (a == 0) return 0;
	if (a == 1) return 1;
	if (a == -1) if (b & 1) return -1;else return 1;
	if (b < 0) return 0;
	ll ans = 1;
	for (int i = 1;i <= b;i++) ans *= a;
	return ans;
}
int main(){
	p = -1;
	gets(s);
	l = strlen(s);
	t[++p] = '0';
	t[++p] = '+';
	for (int i = 0;i < l;i++) if (s[i] != ' ') t[++p] = s[i];
	t[++p] = 0;
	l = p + 1;
	r = 0;
	p = 0;
	while (p < l){
		q = p;
		if ('0' <= t[p] && t[p] <= '9'){
			x = 0;
			while (q + 1 < l && '0' <= t[q + 1] && t[q + 1] <= '9') q++;
			for (int i = p;i <= q;i++) x = x * 10 + t[i] - '0';
			p = q + 1;
			r++;
			f[r].t = 0;
			if (flag){
				x = -x;
				flag = 0;
			}
			f[r].v = x;
			f[r].k = 0;
			continue;
		}
		r++;
		f[r].t = 1;
		f[r].c = t[p++];
		if (p < l && t[p] == '-' && t[p - 1] != ')'){
			flag = 1;
			p++;
		}
	}
	p = q = 0;
	for (int i = 1;i <= r;i++)
		if (f[i].t == 0){
			a[++p] = f[i];
			continue;
		}else{
			if (f[i].c == '('){
				b[++q] = f[i];
				continue;
			}
			if (f[i].c == '+' || f[i].c == '-'){
				while (q && b[q].c != '(') a[++p] = b[q--];
				b[++q] = f[i];
				continue;
			}
			if (f[i].c == '*' || f[i].c == '/'){
				while (q && (b[q].c == '*' || b[q].c == '/' || b[q].c == '^')) a[++p] = b[q--];
				b[++q] = f[i];
				continue;
			}
			if (f[i].c == '^'){
				b[++q] = f[i];
				continue;
			}
			if (f[i].c == ')'){
				while (b[q].c != '(') a[++p] = b[q--];
				q--;
				continue;
			}
		}
	for (int i = q;i >= 1;i--) a[++p] = b[i];
	q = 0;
	for (int i = 1;i <= p;i++)
		if (a[i].t == 0) b[++q] = a[i];
		else{
			if (a[i].c == '+'){
				b[q - 1].v = b[q - 1].v + b[q].v;
				q--;
			}else if (a[i].c == '-'){
				b[q - 1].v = b[q - 1].v - b[q].v;
				q--;
			}else if (a[i].c == '*'){
				if (b[q - 1].k == b[q].k){
					b[q - 1].v = b[q - 1].v * b[q].v;
				}else if (b[q - 1].k == 1){
					b[q - 1].v = b[q].v / b[q - 1].v;
					b[q - 1].k = 0;
				}else{
					b[q - 1].v /= b[q].v;
				}
				q--;
			}else if (a[i].c == '/'){
				if (b[q - 1].k == 0 && b[q].k == 0){
					b[q - 1].v = b[q - 1].v / b[q].v;
				}else if (b[q - 1].k == 0 && b[q].k == 1){
					b[q - 1].v *= b[q].v;
				}else if (b[q - 1].k == 1 && b[q].k == 0){
					b[q - 1].v *= b[q].v;
				}else{
					b[q - 1].v = b[q].v / b[q - 1].v;
				}
				q--;
			}else if (a[i].c == '^'){
				if (b[q].v < 0){
					b[q - 1].k = 1;
					b[q].v = -b[q].v;
				}
				b[q - 1].v = pow(b[q - 1].v,b[q].v);
				q--;
			}
		}
	printf("%d\n",(int)b[1].v);
}
