#include<cstdio>
int a[14];
bool f(int k,int m){
	int n,i,s;
	n=2*k;
	s=0;
	for(i=0;i<k;i++){
		s=(s+m-1)%(n-i);
		if(s<k) return 0;
	}
	return 1;
}
int main(){
	int i,k,n;
	for(k=1;k<=14;k++){
		i=k+1;
        while(1){
			if(f(k,i)){
				a[k]=i;
				break;
			}
			else if(f(k,i+1)){
				a[k]=i+1;
				break;
			}
			i+=k+1;
		}
	}
	scanf("%d",&n);
    printf("%d\n",a[n]);
	return 0;
}
