#include<cstdio>
int a[70][70],x,y;
char s[10],t[10];
const int mm=100000;
int abs(int x){
	return (x>0?x:-x);
}
bool yes(int a,int b){
	int x1=(a-1)/8;
	int x2=(b-1)/8;
	int y1=(a-1)%8+1;
	int y2=(b-1)%8+1;
	return (abs(x1-x2)*abs(y1-y2)==2);
}
int main(){
	for (int i=1;i<=64;i++)
		for (int j=1;j<=64;j++)
			if (i==j) a[i][j]=0;else if (yes(i,j)) a[i][j]=1;else a[i][j]=mm;
	for (int k=1;k<=64;k++)
		for (int i=1;i<=64;i++)
			for (int j=1;j<=64;j++) if (i!=j)
				if (a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
	while (scanf("%s %s",s,t)!=EOF){
		x=(s[0]-'a')*8+s[1]-'0';
		y=(t[0]-'a')*8+t[1]-'0';
		printf("To get from %s to %s takes %d knight moves.\n",s,t,a[x][y]);
	}
}