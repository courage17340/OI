#include <cstdio>
#include <cmath>
const double pi = 3.14159265359;
int n,x[10],y[10],z[10],p0,q0,p1,q1,s;
double d[10][10],r[10],ans;
bool v[10] = {0};
double min(double a,double b){
	return a < b ? a : b;
}
void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}
void work(int k,int a){
	z[k] = a;
	v[a] = 1;
	double R = min(x[a] - p0,y[a] - q0);
	R = min(R,min(p1 - x[a],q1 - y[a]));
	for (int i = 1;i < k;i++) R = min(R,d[z[i]][a] - r[i]);
	if (R < 0) R = 0;
	r[k] = R;
	if (k == n){
		double S = s;
		for (int i = 1;i <= n;i++) S -= pi * r[i] * r[i];
		if (S < ans) ans = S;
		v[a] = 0;
		return;
	}
	for (int i = 1;i <= n;i++) if (!v[i]) work(k + 1,i);
	v[a] = 0;
}
int main(){
	scanf("%d",&n);
	scanf("%d%d%d%d",&p0,&q0,&p1,&q1);
	if (p0 > p1) swap(p0,p1);
	if (q0 > q1) swap(q0,q1);
	s = (p1 - p0) * (q1 - q0);
	if (n == 0){
		printf("%d",s);
		return 0;
	}
	ans = s;
	for (int i = 1;i <= n;i++) scanf("%d%d",&x[i],&y[i]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) d[i][j] = sqrt((x[i] + 0.0 - x[j]) * (x[i] - x[j]) + (y[i] + 0.0 - y[j]) * (y[i] - y[j]));
	for (int i = 1;i <= n;i++) work(1,i);
	printf("%.0f",ans);
}
