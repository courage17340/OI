#include<cstdio>
#include<cstring>
int a,b,x,y,p,q,f[110][2]={{0}},l;
char s[110];
bool flag=0;
int main(){
	scanf("%d%d%s",&a,&b,s);
	l=strlen(s);
	for (int i=1;i<=l;i++)
		if (s[i-1]=='U'){
			f[i][0]=f[i-1][0];
			f[i][1]=f[i-1][1]+1;
		}else
		if (s[i-1]=='D'){
			f[i][0]=f[i-1][0];
			f[i][1]=f[i-1][1]-1;
		}else
		if (s[i-1]=='L'){
			f[i][0]=f[i-1][0]-1;
			f[i][1]=f[i-1][1];
		}else{
			f[i][0]=f[i-1][0]+1;
			f[i][1]=f[i-1][1];
		}
	for (int i=0;i<=l;i++) if (f[i][0]==a&&f[i][1]==b) flag=1;
	for (int i=1;i<=l;i++) if (!flag){
		x=f[i][0];
		y=f[i][1];
		p=f[l][0]-x;
		q=f[l][1]-y;
		if (x+p==0 && p+a==0 && y+q==0 && q+b==0){flag=1;break;}
		if (x+p==0 && p+a==0 && y+q!=0 && (q+b)/(y+q)>=2){flag=1;break;}
		if (y+q==0 && q+b==0 && x+p!=0 && (p+a)/(x+p)>=2){flag=1;break;}
		if (x+p!=0 && y+q!=0 && (p+a)%(x+p)==0 && (q+b)%(y+q)==0 && (p+a)/(x+p)==(q+b)/(y+q) &&(p+a)/(x+p)>=2){flag=1;break;}
	}
	if (flag) printf("Yes");else printf("No");
}
