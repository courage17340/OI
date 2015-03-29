#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string s,t,b[21],c="0123456789";
int a[10];
bool flag;
string g(int x){
	string t="";
	while (x){
		t+=c[x%10];
		x/=10;
	}
	return t;
}
string f(string s){
	string t="";
	int l=s.size();
	memset(a,0,sizeof(a));
	for (int i=0;i<l;i++) a[s[i]-'0']++;
	for (int i=0;i<=9;i++) if (a[i]) t=t+g(a[i])+c[i];
	return t;
}
int main(){
	while (1){
		cin>>s;
		if (s=="-1") break;
		b[0]=s;
		t=b[1]=f(s);
		if (b[0]==b[1]){
			cout<<s<<" is self-inventorying\n";
			continue;
		}
		flag=0;
		for (int i=2;i<=15;i++){
			b[i]=t;
			t=f(b[i]);
			if (b[i]==t){
				cout<<s<<" is self-inventorying after "<<i-1<<" steps\n";
				flag=1;
				break;
			}
		}
		if (flag) continue;
		for (int i=1;i<=15;i++) if(!flag) for (int j=0;j<i;j++) if (b[i]==b[j]){
			flag=1;
			cout<<s<<" enters an inventory loop of length "<<(i-j+1)<<endl;
			break;
		}
		if (flag) continue;
		cout<<s<<" can not be classified after 15 iterations\n";
	}
}