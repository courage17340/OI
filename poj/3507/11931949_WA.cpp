#include<cstdio>
#include<algorithm>
int a[6],ans;
int main(){
	while (1){
		ans=0;
		for (int i=0;i<6;i++) scanf("%d",&a[i]);
		for (int i=0;i<6;i++) ans+=a[i];
		if (ans==0) break;
		ans=0;
		std::sort(a,a+6);
		for (int i=1;i<=4;i++) ans+=a[i];
		printf("%d",ans/4);
		if (ans%4==1) printf(".25");
		if (ans%4==2) printf(".5");
		if (ans%4==1) printf(".75");
		printf("\n");
	}
}