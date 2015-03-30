#include <cstdio>
#include <cmath>
double step,eps = 1e-4,x,y,dx,dy,rx,ry;
int X[1010],Y[1010],W[1010],n;
double f(double x){
	x = sqrt(x);
	if (x < 1e-7) x = 1e-7;
	return x;
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d%d%d",X + i,Y + i,W + i);
	x = y = 0;
	step = 10000;
	while (step > eps){
		dx = dy = 0;
		for (int i = 1;i <= n;i++){
			rx = X[i] - x;
			ry = Y[i] - y;
			dx += rx * W[i] / f(rx * rx + ry * ry);
			dy += ry * W[i] / f(rx * rx + ry * ry);
		}
		rx = dx;
		ry = dy;
		dx = rx * step / f(rx * rx + ry * ry);
		dy = ry * step / f(rx * rx + ry * ry);
		x += dx;
		y += dy;
		step *= 0.9;
	}
	printf("%.2f %.2f\n",x,y);
}
