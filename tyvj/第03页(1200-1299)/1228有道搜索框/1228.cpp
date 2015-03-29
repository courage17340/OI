#include <cstdio>
#include <cstring>
struct node{
	int x;
	node * c[26];
};
node * root,* p;
char s[22],a[10010][22];
int n,l;

void dfs(node * x,int & t){
	if (t == 8) return;
	if (x->x){
		if (t) printf(" ");
		printf("%s",a[x->x]);
		t++;
	}
	for (int i = 0;i < 26;i++){
		if (x->c[i] != 0) dfs(x->c[i],t);
		if (t == 8) return;
	}
}

void work(){
	l = strlen(s);
	p = root;
	for (int i = 0;i < l;i++){
		if (p->c[s[i] - 'a'] == 0){
			printf("%s\n",s);
			return;
		}
		p = p->c[s[i] - 'a'];
	}
	int t = 0;
	dfs(p,t);
	printf("\n");
}

void del(node * x){
	for (int i = 0;i < 26;i++) if (x->c[i] != 0) del(x->c[i]);
	delete x;
}
int main(){
	root = new node;
	for (int i = 0;i < 26;i++) root->c[i] = 0;
	scanf("%d",&n);
	for (int k = 1;k <= n;k++){
		scanf("%s",a[k]);
		strcpy(s,a[k]);
		p = root;
		l = strlen(s);
		for (int i = 0;i < l;i++){
			if (p->c[s[i] - 'a'] == 0){
				p->c[s[i] - 'a'] = new node;
				p->c[s[i] - 'a']->x = 0;
				for (int j = 0;j < 26;j++) p->c[s[i] - 'a']->c[j] = 0;
			}
			p = p->c[s[i] - 'a'];
		}
		p->x = k;
	}
	scanf("%d",&n);
	while (n--){
		scanf("%s",s);
		work();
	}
	del(root);
}
