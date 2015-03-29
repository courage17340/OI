#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct rec{
	int x,y;
};
bool operator <(rec a,rec b){
	return a.x < b.x;
}
bool cmp(rec a,rec b){
	return a.y < b.y;
}
priority_queue <rec> q;
int n,t;
rec a[150010];
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a + 1,a + n + 1,cmp);
	t = 0;
	for (int i = 1;i <= n;i++)
		if (t + a[i].x <= a[i].y){
			q.push(a[i]);
			t += a[i].x;
		}else if (q.top().x > a[i].x){
			t = t - q.top().x + a[i].x;
			q.pop();
			q.push(a[i]);
		}
	printf("%d\n",q.size());
}
