#include <cstdio>
class mat{
public:
double v[2][2];
friend mat operator * (const mat & a,const mat & b){
	mat c;
	for (int i = 0;i < 2;i++) for (int j = 0;j < 2;j++) c.v[i][j] = 0;
	for (int i = 0;i < 2;i++)
		for (int j = 0;j < 2;j++)
			for (int k = 0;k < 2;k++)
				c.v[i][j] += a.v[i][k] * b.v[k][j];
	return c;
}
};
mat x;
double a,b;
int f0,f1,n;
mat pow(mat a,int n){
	int f[40],p = 0;
	mat ans;
	ans.v[0][0] = ans.v[1][1] = 1;
	ans.v[0][1] = ans.v[1][0] = 0;
	while (n){
		f[++p] = n & 1;
		n >>= 1;
	}
	for (int i = p;i >= 1;i--){
		ans = ans * ans;
		if (f[i]) ans = ans * a;
	}
	return ans;
}
int main(){
	scanf("%d%d%lf%lf%d",&f0,&f1,&a,&b,&n);
	if (n == 0) printf("%d",f0);
	else if (n == 1) printf("%d",f1);
	else{
		x.v[0][0] = 0;
		x.v[0][1] = 1;
		x.v[1][0] = b;
		x.v[1][1] = a;
		x = pow(x,n - 1);
		printf("%.0f",x.v[1][0] * f0 + x.v[1][1] * f1);
	}
}
