#include<cstdio>
int a,b,x,n;
bool flag=1;
int main(){
	scanf("%d",&n);
	a=b=0;
	while (n--){
		scanf("%d",&x);
		if (x==25){
			a++;
			continue;
		}
		if (x==50)
			if (a){
				a--;
				b++;
				continue;
			}else{
				flag=0;
				break;
			}
		if (x==100)
			if (a+b*2>=3&&a){
				if (b){
					b--;
					a+=2;
				}
				a-=3;
			}else{
				flag=0;
				break;
			}
	}
	if (flag) printf("YES");else printf("NO");
}
