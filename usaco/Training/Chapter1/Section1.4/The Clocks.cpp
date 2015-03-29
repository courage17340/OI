/*
USER: curage2
PROG: clocks
LANG: C++
*/
#include<cstdio>
#include<string>
using namespace std;
struct rec{int v[10];};
rec a;
string ans,null="";
int b[10][10]={{0},{0,1,1,0,1,1,0,0,0,0},{0,1,1,1,0,0,0,0,0,0},{0,0,1,1,0,1,1,0,0,0},
				{0,1,0,0,1,0,0,1,0,0},{0,0,1,0,1,1,1,0,1,0},{0,0,0,1,0,0,1,0,0,1},
				{0,0,0,0,1,1,0,1,1,0},{0,0,0,0,0,0,0,1,1,1},{0,0,0,0,0,1,1,0,1,1}};
void work(string s,rec a,int k){
	if (ans != null && s.size() > ans.size()) return;
	string t=null;
	if (k < 10) for (int i = 0;i < 4;i++){
		work(s + t,a,k + 1);
		t = t + char(k + '0');
	}
	if (k == 10) if (ans == null || s.size() < ans.size() || (s.size() == ans.size() && s < ans)){
		int l = s.size();
		for (int i = 0;i < l;i++)
			for (int j = 1;j <= 9;j++)
				a.v[j] =((a.v[j] + b[s[i] - '0'][j] - 1) & 3) + 1;
		for (int i = 1;i <= 9;i++) if (a.v[i] != 4) return;
		ans = s;
	}
}
int main(){
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	for (int i = 1;i <= 9;i++){
		scanf("%d",&a.v[i]);
		a.v[i] /= 3;
	}
	ans = null;
	work(null,a,1);
	int l = ans.size();
	for (int i = 0;i < l - 1;i++) printf("%c ",ans[i]);
	printf("%c\n",ans[l - 1]);
}
