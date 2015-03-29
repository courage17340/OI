#include<cstdio>
int a[2000010],n,x,q,p,flag;
int main(){
	scanf("%d",&n);
	q=0;
	flag=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x==-1 && q) printf("%d\n",a[q--]);
		if (x==0 && flag){
			p=q*2;
			for (int i=q+1;i<=p;i++) a[i]=a[i-q];
			q=p;
			if (q>=n) flag=0;
		}
		if (x>0) a[++q]=x;
	}
}
