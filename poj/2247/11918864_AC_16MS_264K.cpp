#include<cstdio>
int f[6000],a[4][6000]={0},x,r[4],s[4],p,b[4]={2,3,5,7};
void print(int x){
	printf("The %d",x);
	if (x%10==1 && x%100!=11) printf("st");
		else if (x%10==2 && x%100!=12) printf("nd");
			else if (x%10==3 && x%100!=13) printf("rd");
				else printf("th");
	printf(" humble number is %d.\n",f[x]);
}
int main(){
	for (int i=0;i<4;i++) a[i][1]=r[i]=s[i]=1;
	for (int i=1;i<=5842;i++){
		p=0;
		for (int j=1;j<4;j++) if (a[j][r[j]]<a[p][r[p]]) p=j;
		f[i]=a[p][r[p]];
		for (int j=0;j<=3;j++){
			s[j]++;
			a[j][s[j]]=f[i]*b[j];
		}
		for (int j=0;j<4;j++)
			if (a[j][r[j]]==f[i]) r[j]++;
	}
	while (1){
		scanf("%d",&x);
		if (x==0) break;
		print(x);
	}
}