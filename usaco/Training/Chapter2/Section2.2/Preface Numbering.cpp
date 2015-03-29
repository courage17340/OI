/*
ID: courage2
TASK: preface
LANG: C++
*/
#include <cstdio>
char s[10] = " IVXLCDM";
int n,a[10] = {0};
void work(int x){
	if (x >= 1000){
		a[7] += x / 1000;
		work(x % 1000);
		return;
	}
	if (x >= 900){
		a[5]++;
		a[7]++;
		work(x - 900);
		return;
	}
	if (x >= 500){
		a[6]++;
		work(x - 500);
		return;
	}
	if (x >= 400){
		a[5]++;
		a[6]++;
		work(x - 400);
		return;
	}
	if (x >= 100){
		a[5] += x / 100;
		work(x % 100);
		return;
	}
	if (x >= 90){
		a[3]++;
		a[5]++;
		work(x - 90);
		return;
	}
	if (x >= 50){
		a[4]++;
		work(x - 50);
		return;
	}
	if (x >= 40){
		a[3]++;
		a[4]++;
		work(x - 40);
		return;
	}
	if (x >= 10){
		a[3] += x / 10;
		work(x % 10);
		return;
	}
	if (x >= 9){
		a[1]++;
		a[3]++;
		work(x - 9);
		return;
	}
	if (x >= 5){
		a[2]++;
		work(x - 5);
		return;
	}
	if (x >= 4){
		a[1]++;
		a[2]++;
		work(x - 4);
		return;
	}
	a[1] += x;
}
int main(){
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) work(i);
	int k = 7;
	while (!a[k]) k--;
	for (int i = 1;i <= k;i++) printf("%c %d\n",s[i],a[i]);
}
