#include<cstdio>
#include<cmath>
double a[3][2],x,y,p,q,r,s,l1,l2;
double dis(double x,double y,double p,double q){
    return sqrt((x-p)*(x-p)+(y-q)*(y-q));
}
int main(){
    for (int i=0;i<3;i++) scanf("%lf%lf",&a[i][0],&a[i][1]);
    l1=dis(a[0][0],a[0][1],a[1][0],a[1][1]);
    l2=dis(a[0][0],a[0][1],a[2][0],a[2][1]);
    p=a[1][0];
    q=a[1][1];
    r=a[2][0];
    s=a[2][1];
    while (dis(p,q,r,s)>1e-3){
        x=(p+r)/2;
        y=(q+s)/2;
        if (dis(x,y,a[1][0],a[1][1])*l2<l1*dis(x,y,a[2][0],a[2][1])){
            p=x;
            q=y;
        }else{
            r=x;
            s=y;
        }
    }
    printf("%.2lf %.2lf",x,y);
}
