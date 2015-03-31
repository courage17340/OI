#include <cstdio>
typedef long long ll;
int t;
ll n,k,d1,d2,x,y,z,p,q;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
		bool flag = 0;
		for (int k1 = -1;k1 <= 1;k1 += 2)
			for (int k2 = -1;k2 <= 1;k2 += 2){
				x = 0;
				y = x + d1 * k1;
				z = y + d2 * k2;
				p = x;
				if (p > y) p = y;
				if (p > z) p = z;
				x -= p;
				y -= p;
				z -= p;
				ll tmp1 = k - (x + y + z);
				if (tmp1 < 0 || tmp1 % 3) continue;
				ll tmp2 = n - k;
				p = x;
				if (p < y) p = y;
				if (p < z) p = z;
				tmp2 -= (p - x);
				tmp2 -= (p - y);
				tmp2 -= (p - z);
				if (tmp2 < 0 || tmp2 % 3) continue;
				flag = 1;
				break;
			}
		puts(flag ? "yes" : "no");
	}
}
