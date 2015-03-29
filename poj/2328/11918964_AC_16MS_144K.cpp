#include<cstdio>
int x,l,r,ans;
char s[20];
int main(){
	while (1){
		l=0;
		r=11;
		scanf("%d",&x);
		if (x==0) break;
		scanf("%s",s);
		scanf("%s",s);
		if (s[0]=='h') r=x;
		if (s[0]=='l') l=x;
		if (s[0]=='o'){
			printf("Stan may be honest\n");
			continue;
		}
		while (1){
			scanf("%d",&x);
			scanf("%s",s);
			scanf("%s",s);
			if (s[0]=='h') r=(r<x?r:x);
			if (s[0]=='l') l=(l>x?l:x);
			if (s[0]=='o'){
				ans=x;
				break;
			}
		}
		if (l<ans && ans<r) printf("Stan may be honest\n");else printf("Stan is dishonest\n");
	}
}