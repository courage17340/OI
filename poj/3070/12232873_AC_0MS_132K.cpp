#include<cstdio>
#include<cstring>
const int md=10000;
int n,f[40],p;
class mat{
public:
int v[2][2];

friend mat operator *(mat a,mat b){
	mat c;
	memset(c.v,0,sizeof(c.v));
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
				c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%md;
	return c;
}
};
mat a,b;
int main(){
	a.v[0][0]=a.v[0][1]=a.v[1][0]=1;
	a.v[1][1]=0;
	while (scanf("%d",&n)){
		if (n==-1) break;
		if (n==0){
			printf("0\n");
			continue;
		}
		b.v[0][0]=b.v[1][1]=1;
		b.v[0][1]=b.v[1][0]=0;
		p=0;
		n--;
		while (n){
			f[++p]=n&1;
			n>>=1;
		}
		for (int i=p;i>=1;i--){
			b=b*b;
			if (f[i]) b=b*a;
		}
		printf("%d\n",b.v[0][0]);
	}
}