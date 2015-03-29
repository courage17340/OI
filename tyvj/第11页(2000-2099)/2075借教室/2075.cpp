#include<cstdio>
#include<cstring>
typedef long long ll;
int n,l,r,m,ans,a[1000010],b[1000010][3],s;
ll f[1000010]={0},x;
bool yes(int k){
	x = 0;
	if (s <= k) for (int i = s + 1;i <= k;i++){
		f[b[i][1]] += b[i][0];
		f[b[i][2] + 1] -= b[i][0];
	} else for (int i = k + 1;i <= s;i++){
		f[b[i][1]] -= b[i][0];
		f[b[i][2] + 1] += b[i][0];
	}
	s = k;
	for (int i = 1;i <= n;i++){
		x += f[i];
		if (x > a[i]) return 0;
	}
	return 1;
}
int main(){
	s = 0;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= m;i++) scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
	if (yes(m)){
		printf("0\n");
		return 0;
	}
	l = 1;
	r = m;
	while (l < r){
		ans = (l + r) >> 1;
		if (yes(ans)) l = ans + 1;else r = ans;
	}
	printf("-1\n%d\n",l);
}
