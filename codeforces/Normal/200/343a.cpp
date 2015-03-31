#include<iostream>
using namespace std;
long long a,b,t,ans=0;
int main(){
	cin>>a>>b;
	while (b!=0){
		ans+=a/b;
		a%=b;
		t=a;
		a=b;
		b=t;
	}
	cout<<ans;
}
