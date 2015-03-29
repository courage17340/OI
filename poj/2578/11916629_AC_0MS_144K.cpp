#include<cstdio>
int a[3],d=168,p=0;
int main(){
	for (int i=0;i<3;i++) scanf("%d",&a[i]);
	for (int i=0;i<3;i++) if (a[i]<=d){
		p=1;
		printf("CRASH %d\n",a[i]);
		break;
	}
	if (p==0) printf("NO CRASH\n");
}