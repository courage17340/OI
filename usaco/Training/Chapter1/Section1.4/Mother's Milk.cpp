/*
ID: courage2
PROG: milk3
LANG: C++
*/
#include <cstdio>
int a[3],y[3],p,q;
bool v[21][21][21] = {{{0}}},f[21] = {0};
struct rec{int v[3];};
rec b[10010];
void pour(int a[],int i,int j){
	if (a[i] + a[j] > y[j]){
		a[i] = a[i] + a[j] - y[j];
		a[j] = y[j];
	}else{
		a[j] += a[i];
		a[i] = 0;
	}
}
int main(){
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	for (int i = 0;i < 3;i++) scanf("%d",a + i);
	for (int i = 0;i < 3;i++) y[i] = a[i];
	v[0][0][a[2]] = 1;
	f[a[2]] = 1;
	a[0] = a[1] = 0;
	p = q = 1;
	b[p].v[0] = 0;
	b[p].v[1] = 0;
	b[p].v[2] = a[2];
	while (p <= q){
		if (b[p].v[0] == 0) f[b[p].v[2]] = 1;
		for (int i = 0;i < 3;i++)
			for (int j = 0;j < 3;j++) if (i != j){
				for (int k = 0;k < 3;k++) a[k] = b[p].v[k];
				pour(a,i,j);
				if (!v[a[0]][a[1]][a[2]]){
					q++;
					v[a[0]][a[1]][a[2]] = 1;
					for (int k = 0;k < 3;k++) b[q].v[k] = a[k];
				}
			}
		p++;
	}
	for (int i = 0;i < y[2];i++) if (f[i]) printf("%d ",i);
	printf("%d\n",y[2]);
}
