#include<cstdio>
const int md=1000000007;
int n,m,a[2010],b[2010],pow[2010],c[2010][2010]={{0}},p,q,r,s,x,k,ans;
bool v[2010]={0};
int main(){
	scanf("%d",&n);
	p=q=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x==-1){
			p++;
			a[p]=i;
		}else v[x]=1;
	}
	for (int i=1;i<=n;i++) if (!v[i]){
		q++;
		b[q]=i;
	}
	m=0;
	s=r=0;
	while (s<p){
		s++;
		while (r<=q && a[s]>b[r]) r++;
		if (r>q) break;
		if (a[s]==b[r]) m++;
	}
	pow[0]=1;
	for (int i=1;i<=p;i++) pow[i]=(long long)pow[i-1]*i%md;
	c[0][0]=1;
	for (int i=1;i<=m;i++)
		for (int j=0;j<=m;j++)
			if (j==0 || j==m) c[i][j]=1;else c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
	ans=0;
	k=1;
	for (int i=0;i<=m;i++){
		ans=((long long)pow[p-i]*k*c[m][i]+ans)%md;
		if (ans<0) ans+=md;
		k=-k;
	}
	printf("%d",ans);
}
