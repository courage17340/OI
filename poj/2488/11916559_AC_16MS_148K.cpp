#include<cstdio>
#include<cstring>
struct rec{int x,y;};
rec a[30];
rec b[8]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
bool v[27][27],flag;
int n,m,t;
void search(int k,int x,int y){
	int p,q;
	a[k].x=x;
	a[k].y=y;
	if (k==m*n){
		flag=1;
		for (int i=1;i<=k;i++) printf("%c%d",a[i].x+64,a[i].y);
		printf("\n\n");
		return;
	}
	for (int i=0;i<8;i++){
		p=x+b[i].x;
		q=y+b[i].y;
		if (1<=p && p<=m && 1<=q && q<=n && !v[p][q]){
			v[p][q]=1;
			search(k+1,p,q);
			if (flag) return;
			v[p][q]=0;
		}
	}
}
int main(){
	scanf("%d",&t);
	for (int w=1;w<=t;w++){
		scanf("%d%d",&n,&m);
		printf("Scenario #%d:\n",w);
		if (n*m==1){
			printf("A1\n\n");
			continue;
		}
		if (n<=2 || m<=2 || m*n==9){
			printf("impossible\n\n");
			continue;
		}
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		v[1][1]=1;
		flag=0;
		search(1,1,1);
		if (!flag) printf("impossible\n\n");
	}
}