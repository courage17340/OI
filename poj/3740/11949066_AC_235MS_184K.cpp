#include<cstdio>
#include<cstring>
int a[17][310],s[17],f[17],n,m;
bool flag,g[310];
void search(int x,int k){
	if (flag) return;
	f[x]=k;
	int p=0;
	for (int i=1;i<=x;i++) p+=s[i]*f[i];
	if (p==m){
		memset(g,0,sizeof(g));
		flag=1;
		for (int i=1;i<=x;i++) if (f[i] && flag){
			for (int j=1;j<=m;j++) if (a[i][j])
				if (g[j]){
					flag=0;
					break;
				}else g[j]=1;
		}
		return;
	}
	if (x==n || p>m) return ;
	search(x+1,1);
	search(x+1,0);
}
int main(){
	while (scanf("%d%d",&n,&m)!=EOF){
		memset(s,0,sizeof(s));
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			s[i]+=a[i][j];
		}
		memset(f,0,sizeof(f));
		flag=0;
		search(1,1);
		search(1,0);
		if (flag) printf("Yes, I found it\n");else printf("It is impossible\n");
	}
}