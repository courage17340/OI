#include <cstdio>
typedef long long ll;
int n,m,k,x,y,k1,k2,a[100010];

void swap(int & a,int & b){
	int t = a;
	a = b;
	b = t;
}

void ud(int x){
	if (x * 2 > n) return;
	if (x * 2 == n){
		if (a[x] > a[x * 2]) swap(a[x],a[x * 2]);
		return;
	}
	int k = x;
	if (a[k] > a[x * 2]) k = x * 2;
	if (a[k] > a[x * 2 + 1]) k = x * 2 + 1;
	if (k == x) return;
	swap(a[k],a[x]);
	ud(k);
}

void du(int x){
	if (x == 1 || a[x] >= a[x >> 1]) return;
	swap(a[x],a[x >> 1]);
	du(x >> 1);
}

int main(){
	while (scanf("%d%d%d%d%d",&a[1],&k1,&k2,&m,&k) != EOF){
		n = 1;
		for (int i = 1;i < k;i++){
			x = ((ll)a[1] * k1 + 1) % m;
			y = ((ll)a[1] * k2 + 1) % m;
			swap(a[1],a[n]);
			n--;
			ud(1);
			a[++n] = x;
			du(n);
			a[++n] = y;
			du(n);
		}
		printf("%d\n",a[1]);
	}
}
