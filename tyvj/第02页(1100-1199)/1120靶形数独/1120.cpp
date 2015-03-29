#include<cstdio>
int a[10][10],b[10][10],ans=0,k,p,q,f[82][2];
bool c[10][10]={0},d[10][10]={0},e[10][10]={0};
int ff(int x,int y){
	if (x==1 || y==1 || x==9 || y==9) return 6;
	if (x==2 || y==2 || x==8 || y==8) return 7;
	if (x==3 || y==3 || x==7 || y==7) return 8;
	if (x==4 || y==4 || x==6 || y==6) return 9;
	return 10;
}
bool yes(int x,int y,int k){
	if (a[x][y]) return 0;
	if (c[x][k]) return 0;
	if (d[y][k]) return 0;
	if (e[(x-1)/3*3+(y-1)/3+1][k]) return 0;
	return 1;
}
int sum(){
	int x=0;
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
			x+=a[i][j]*b[i][j];
	return x;
}
int g(int x,int y){
	int h=0;
	for (int i=1;i<=9;i++) if (yes(x,y,i)) h++;
	return h;
}
void search(int x,int y,int z,int step){
	int m=10,p,q,r;
	a[x][y]=z;
	c[x][z]=1;
	d[y][z]=1;
	e[(x-1)/3*3+(y-1)/3+1][z]=1;
	if (step==k){
		if (sum()>ans) ans=sum();
		a[x][y]=0;
		c[x][z]=0;
		d[y][z]=0;
		e[(x-1)/3*3+(y-1)/3+1][z]=0;
		return;
	}
	for (int i=1;i<=k;i++)
		if (a[f[i][0]][f[i][1]]==0 && m>g(f[i][0],f[i][1])){
			m=g(f[i][0],f[i][1]);
			r=i;
		}
	p=f[r][0];
	q=f[r][1];
	for (int i=1;i<=9;i++)
		if (yes(p,q,i)) search(p,q,i,step+1);
	a[x][y]=0;
	c[x][z]=0;
	d[y][z]=0;
	e[(x-1)/3*3+(y-1)/3+1][z]=0;
}
int main(){
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++) scanf("%d",&a[i][j]);
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++) b[i][j]=ff(i,j);
	k=0;
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
			if (a[i][j]==0){
				k++;
				f[k][0]=i;
				f[k][1]=j;
			}
	p=f[1][0];
	q=f[1][1];
	for (int i=1;i<=9;i++) for (int j=1;j<=9;j++) if (a[i][j]){
		c[i][a[i][j]]=1;
		d[j][a[i][j]]=1;
		e[(i-1)/3*3+(j-1)/3+1][a[i][j]]=1;
	}
	search(0,0,0,0);
	if (ans==0) ans=-1;
	printf("%d\n",ans);
}
