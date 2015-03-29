#include <cstdio>
#include <cstring>
const int N = 210;
int a[N + 1],b[N + 1] = {0},n,m,t,k;
char s[N];
typedef long long ll;
ll tmp;
int main(){
	scanf("%s%d%d",s,&m,&t);
	if (t > m) t = m;
	n = strlen(s);
	for (int i = 0;i < n;i++) a[i - n + 1 + N] = s[i] - '0';
	for (int i = N + 1 - n;i <= N;i++)
		for (int j = N + 1 - n;j <= N;j++) b[i + j - N] += a[i] * a[j];
	k = 0;
	for (int i = N;i >= 0;i--){
		b[i] += k;
		k = b[i] / 10;
		b[i] %= 10;
	}
	k = 0;
	for (int i = N;i >= 0;i--){
		tmp = (ll)b[i] * t + k;
		k = tmp / 10;
		b[i] = tmp % 10;
	}
	tmp = 0;
	for (int i = 0;i <= N;i++){
		tmp = tmp * 10 + b[i];
		b[i] = tmp / m;
		tmp %= m;
	}
	k = 0;
	while (k < N && !b[k]) k++;
	for (int i = k;i <= N;i++) printf("%d",b[i]);
	printf("??\n");
}
