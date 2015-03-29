#include<cstdio>
#include<cstring>
struct rec{int v[41];};
int a[81][81],n,m,t;
rec f[81][81]={0},ans[81]={0},g[81]={0},c;
rec sum(rec a,rec b){
	rec c;
	for (int i=0;i<=40;i++) c.v[i]=a.v[i]+b.v[i];
	int j=0;
	for (int i=40;i>=0;i--){
		c.v[i]+=j;
		j=c.v[i]/10;
		c.v[i]%=10;
	}
	return c;
}
rec pow(int x,int k){
	rec c;
	for (int i=0;i<=40;i++) c.v[i]=x*g[k].v[i];
	int j=0;
	for (int i=40;i>=0;i--){
		c.v[i]+=j;
		j=c.v[i]/10;
		c.v[i]%=10;
	}
	return c;
}
rec max(rec a,rec b){
	for (int i=0;i<=40;i++) if (a.v[i]!=b.v[i])
		if (a.v[i]>b.v[i]) return a;else return b;
	return a;
}
void print(rec a){
	int i=0;
	while (a.v[i]==0 && i<40) i++;
	for (int j=i;j<=40;j++) printf("%d",a.v[j]);
	printf("\n");
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	g[0].v[40]=1;
	for (int i=1;i<=m;i++){
		for (int j=0;j<=40;j++) g[i].v[j]=g[i-1].v[j]*2;
		t=0;
		for (int j=40;j>=0;j--){
			g[i].v[j]+=t;
			t=g[i].v[j]/10;
			g[i].v[j]%=10;
		}
	}
	for (int k=1;k<=n;k++){
		memset(f,0,sizeof(f));
		for (int q=m-2;q>=0;q--)
			for (int i=1;q+i<=m;i++){
				int j=i+q;
				if (i>1) f[i][j]=sum(f[i-1][j],pow(a[k][i-1],m-1-q));
				if (j<m) f[i][j]=max(f[i][j],sum(f[i][j+1],pow(a[k][j+1],m-1-q)));
			}
		for (int i=1;i<=m;i++) ans[k]=max(ans[k],sum(f[i][i],pow(a[k][i],m)));
	}
	for (int i=1;i<=n;i++) ans[0]=sum(ans[0],ans[i]);
	print(ans[0]);
}
