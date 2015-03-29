#include<iostream>
#include<string>
using namespace std;
string a[21];
int v[21]={0},f[21][21]={0},n,ans;
char s[100];
int g(string a,string b){
	b.copy(s,b.size(),0);
	for (int i=1;i<b.size() && i<a.size();i++)
		if (a.rfind(s,a.size()-1,i)>=0 && a.rfind(s,a.size()-1,i)+i==a.size()) return i;
	return 0;
}
void work(int k,int len){
	v[k]++;
	if (ans<len) ans=len;
	for (int i=1;i<=n;i++) if (v[i]<2 && f[k][i]) work(i,len+a[i].size()-f[k][i]);
	v[k]--;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	cin>>a[0];
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=g(a[i],a[j]);
	ans=0;
	for (int i=1;i<=n;i++) if (a[i][0]==a[0][0]) work(i,a[i].size());
	cout<<ans;
}
