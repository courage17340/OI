#include<cstdio>
int a[200010],b[200010],k,p,n,x,y,d;
char s[3];
int search(int l,int r,int k){
	int m=(l+r)>>1;
	while (l!=r){
		if (b[m]<k) l=m+1;
		if (b[m]==k) return m;
		if (b[m]>k) r=m;
		m=(l+r)>>1;
	}
	return m;
}
int main(){
	scanf("%d%d",&n,&d);
	x=k=0;
	p=0;
	for (int i=1;i<=n;i++){
		scanf("%s%d",s,&y);
		if (s[0]=='A'){
			y=(x+y)%d;
			k++;
			a[k]=y;
			while (p>0 && a[b[p]]<=y) p--;
			p++;
			b[p]=k;
		}
		if (s[0]=='Q'){
			x=a[b[search(1,p,k-y+1)]];
			printf("%d\n",x);
		}
	}
}
