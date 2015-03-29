/*
USER: courage2
LANG: C++
TASK: fence
*/
#include <cstdio>
int n,x,y,a[510][510],d[510] = {0},ans[1110],m;
bool f;
void search(int x){
	if (d[x] == 0){
		ans[++m] = x;
		return;
	}
	for (int i = 1;i <= 500;i++) if (a[x][i]){
		a[x][i]--;
		a[i][x]--;
		d[x]--;
		d[i]--;
		search(i);
	}
	ans[++m] = x;
}
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d",&x,&y);
		d[x]++;
		d[y]++;
		a[x][y]++;
		a[y][x]++;
	}
	f = 0;
	for (int i = 1;i <= 500;i++) if (d[i] & 1){
		x = i;
		f = 1;
		break;
	}
	if (!f) for (int i = 1;i <= 500;i++) if (d[i]){
		x = i;
		break;
	}
	m = 0;
	search(x);
	for (int i = m;i >= 1;i--) printf("%d\n",ans[i]);
}
