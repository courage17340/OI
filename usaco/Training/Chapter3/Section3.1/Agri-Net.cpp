/*
ID: courage2
TASK: agrinet
LANG: C++
*/
#include <cstdio>
#include <algorithm>
struct rec{int x,y,z;};
rec a[10010];
int n,m = 0,f[110],ans = 0;
int father(int x){
	if (f[x] == x) return x;
	return f[x] = father(f[x]);
}
bool cmp(rec a,rec b){
	return a.z < b.z;
}
int main(){
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++){
			m++;
			a[m].x = i;
			a[m].y = j;
			scanf("%d",&a[m].z);
		}
	std::sort(a + 1,a + m + 1,cmp);
	for (int i = 1;i <= m;i++) if (father(a[i].x) != father(a[i].y)){
		ans += a[i].z;
		f[f[a[i].x]] = f[a[i].y];
	}
	printf("%d\n",ans);
}
