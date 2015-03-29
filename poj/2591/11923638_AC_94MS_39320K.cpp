#include<cstdio>
#include<cstring>
int f[10000010],p,q,x;
int main(){
	f[1]=p=q=1;
	for (int i=2;i<=10000000;i++){
		if (f[p]*2+1<=f[q]*3+1){
			f[i]=f[p]*2+1;
			p++;
			if (f[q]*3+1==f[i]) q++;
		}else{
			f[i]=f[q]*3+1;
			q++;
			if (f[p]*2+1==f[i]) p++;
		}
	}
	while (scanf("%d",&x)!=EOF) printf("%d\n",f[x]);
}