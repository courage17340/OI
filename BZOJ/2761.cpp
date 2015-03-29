#include <cstdio>
#include <set>
using namespace std;
int a[50010],n,x,p,t;
set<int> s;
int main(){
	scanf("%d",&t);
	while (t--){
		s.clear();
		p = 0;
		scanf("%d",&n);
		for (int i = 1;i <= n;i++){
			scanf("%d",&x);
			if (s.count(x)) continue;
			s.insert(x);
			a[++p] = x;
		}
		for (int i = 1;i < p;i++) printf("%d ",a[i]);
		printf("%d\n",a[p]);
	}
}
