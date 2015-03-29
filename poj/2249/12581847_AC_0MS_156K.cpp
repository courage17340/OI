#include <cstdio>
#include <cstring>
typedef long long ll;
int n,k;
double ans;
int main(){
	while (1){
		scanf("%d%d",&n,&k);
		if (!n) break;
		if (n - k <= k) k = n - k;
		if (k == 0) printf("1\n");else
		if (k == 1) printf("%d\n",n);else
		if (k == 2) printf("%d\n",(ll)n * (n - 1) / 2);else{
			ans = 1;
			for (int i = 1;i <= k;i++) ans = ans * (n + 1 - i) / i;
			printf("%.0f\n",ans);
		}
	}
}