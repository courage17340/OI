#include <cstdio>
#include <cstring>
int t,n,a[510][510],p,q,ans;
bool v[510];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) scanf("%d",&a[i][j]);
		memset(v,0,sizeof(v));
		p = 1;
		q = 2;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++) if (i != j && a[i][j] < a[p][q]){
				p = i;
				q = j;
			}
		v[p] = v[q] = 1;
		ans = a[p][q];
		for (int k = 3;k <= n;k++){
			a[0][0] = 1e9;
			p = q = 0;
			for (int i = 1;i <= n;i++) if (v[i])
				for (int j = 1;j <= n;j++) if (!v[j] && a[i][j] < a[p][q]){
					p = i;
					q = j;
				}
			v[q] = 1;
			if (ans < a[p][q]) ans = a[p][q];
		}
	}
	printf("%d\n",ans);
}