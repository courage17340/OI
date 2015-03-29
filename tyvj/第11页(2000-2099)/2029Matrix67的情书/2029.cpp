#include<iostream>
#include<string>
using namespace std;
int f[26]={0},p,k,l,t;
string s[50010];
char g(char c){
	int k;
	if ('a'<=c && c<='z'){
		k=c-'a'+t;
		if (k<0) k+=26;else if (k>25) k-=26;
		return ('a'+k);
	}else if ('A'<=c && c<='Z'){
		k=c-'A'+t;
		if (k<0) k+=26;else if (k>25) k-=26;
		return ('A'+k);
	}else return c;
}
void work(char c){
	if ('a'<=c && c<='z') f[c-'a']++;
	if ('A'<=c && c<='Z') f[c-'A']++;
}
int main(){
	p=0;
	while (getline(cin,s[p+1])){
		p++;
		l=s[p].size();
		for (int i=0;i<l;i++) work(s[p][i]);
	}
	k=0;
	for (int i=1;i<26;i++) if (f[i]>f[k]) k=i;
	t=4-k;
	for (int i=1;i<=p;i++){
		l=s[i].size();
		for (int j=0;j<l;j++) s[i][j]=g(s[i][j]);
	}
	for (int i=1;i<=p;i++) cout<<s[i]<<endl;
}
	
