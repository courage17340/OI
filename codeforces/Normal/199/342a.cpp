#include<cstdio>
int n,a[10]={0},x;
void work(){
	if (a[5] || a[7] || a[1]!=n/3){
		printf("-1");
		return;
	}
	if (a[1]==a[2] && a[2]==a[4]){
		while (a[1]--) printf("1 2 4\n");
		return;
	}
	if (a[1]==a[2] && a[2]==a[6]){
		while (a[1]--) printf("1 2 6\n");
		return;
	}
	if (a[1]==a[3] && a[3]==a[6]){
		while (a[1]--) printf("1 3 6\n");
		return;
	}
	if (a[1]==a[2] && a[4]+a[6]==a[2]){
		while (a[4]--) printf("1 2 4\n");
		while (a[6]--) printf("1 2 6\n");
		return;
	}
	if (a[1]==a[6] && a[2]+a[3]==a[1]){
		while (a[2]--) printf("1 2 6\n");
		while (a[3]--) printf("1 3 6\n");
		return;
	}
	if (a[2]==a[4] && a[3]==a[6] && a[2]+a[3]==a[1]){
		while (a[2]--) printf("1 2 4\n");
		while (a[3]--) printf("1 3 6\n");
		return;
	}
	if (a[2]+a[3]==a[1] && a[4]+a[6]==a[1] && a[2]>a[4] && a[6]>a[3]){
		a[2]-=a[4];
		while (a[4]--) printf("1 2 4\n");
		while (a[2]--) printf("1 2 6\n");
		while (a[3]--) printf("1 3 6\n");
		return;
	}
	printf("-1");	
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	work();
}
