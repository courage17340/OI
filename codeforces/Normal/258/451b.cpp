#include <cstdio>
#include <algorithm>
struct rec{int x,i;};
rec a[100010];
int n,m,b[100010],x,y;
bool cmp(rec a,rec b){
	return a.x < b.x;
}
void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i].x);
		a[i].i = i;
	}
	std::sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++) b[a[i].i] = i;
	x = 0;
	y = n + 1;
	for (int i = 1;i <= n;i++) if (b[i] != i){
		x = i;
		break;
	}
	for (int i = n;i >= 1;i--) if (b[i] != i){
		y = i;
		break;
	}
	if (x == 0 && y == n + 1){
		x = 1;
		y = 1;
	}
	for (int i = x,j = y;i < j;i++,j--){
		swap(b[i],b[j]);
	}
	for (int i = 1;i <= n;i++) if (b[i] != i){
		puts("no");
		return 0;
	}
	printf("yes\n%d %d\n",x,y);
}
