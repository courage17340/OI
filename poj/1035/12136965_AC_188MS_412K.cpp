#include<cstdio>
#include<cstring>
char b[10010][20],s[20];
int l[10010],a[10010],k,p,q,len,flag;
inline int abs(int x){
	return (x>0?x:-x);
}
int yes(int x){
	int p,q,k;
	if (abs(len-l[x])>1) return 0;
	if (strcmp(b[x],s)==0) return 1;
	if (len==l[x]){
		p=q=k=0;
		while (p<len){
			if (s[p]!=b[x][q]) k++;
			p++;
			q++;
		}
		if (k>1) return 0;else return 2;
	}
	if (len>l[x]){
		p=q=k=0;
		while (p<len && q<l[x])
			if (s[p]==b[x][q]){
				p++;
				q++;
			}else{
				k++;
				p++;
			}
		if (k>1) return 0;else return 2;
	}
	p=q=k=0;
	while (p<len && q<l[x])
		if (s[p]==b[x][q]){
			p++;
			q++;
		}else{
			k++;
			q++;
		}
	if (k>1) return 0;else return 2;
}
int main(){
	p=0;
	while (1){
		scanf("%s",s);
		if (s[0]=='#') break;
		p++;
		strcpy(b[p],s);
		l[p]=strlen(s);
	}
	while (1){
		scanf("%s",s);
		if (s[0]=='#') break;
		len=strlen(s);
		flag=q=0;
		for (int i=1;i<=p;i++){
			k=yes(i);
			if (k==0) continue;
			if (k==1){
				flag=1;
				break;
			}
			q++;
			a[q]=i;
		}
		if (flag) printf("%s is correct\n",s);else{
			printf("%s:",s);
			for (int i=1;i<=q;i++) printf(" %s",b[a[i]]);
			printf("\n");
		}
	}
}