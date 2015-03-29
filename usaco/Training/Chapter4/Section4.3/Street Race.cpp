/*
USER: courage2
LANG: C++
TASK: race3
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector <int> a[52],ans1,ans2;
bool u[52],v[52],flag;
int n,x,y;
void search(bool v[],int x,int k){
	v[x] = 1;
	for (int i = 0;i < a[x].size();i++) if (!v[a[x][i]] && a[x][i] != k) search(v,a[x][i],k);
}
void out(const vector <int> &a){
	printf("%d",a.size());
	for (int i = 0;i < a.size();i++) printf(" %d",a[i]);
	printf("\n");
}
int main(){
	freopen("race3.in","r",stdin);
	freopen("race3.out","w",stdout);
	n = -1;
	while (1){
		scanf("%d",&x);
		if (x == -1) break;
		n++;
		while (x != -2){
			a[n].push_back(x);
			scanf("%d",&x);
		}
	}
	for (int k = 1;k < n;k++){
		memset(v,0,sizeof v);
		search(v,0,k);
		if (!v[n]) ans1.push_back(k);
	}
	for (int i = 0;i < ans1.size();i++){
		memset(v,0,sizeof v);
		memset(u,0,sizeof u);
		search(v,ans1[i],-1);
		search(u,0,ans1[i]);
		flag = 1;
		for (int j = 0;j <= n;j++) flag &= (v[j] ^ u[j]);
		if (flag) ans2.push_back(ans1[i]);
	}
	out(ans1);
	out(ans2);
}
