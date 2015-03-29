#include <cstdio>
#include <cstring>
struct node{bool f;node *c[2];};
node *root,*p,*q,pool[200];
int l,te = 0,x = 0;
char s[20];
bool f,g;
node *get(){
	x++;
	if (x > 199) x = 0;
	return &pool[x];
}
int main(){
	while (1){
		te++;
		if (scanf("%s",s) == EOF) break;
		f = 1;
		root = get();
		root->f = 0;
		root->c[0] = root->c[1] = 0;
		while (s[0] != '9'){
			if (!f){
				scanf("%s",s);
				continue;
			}
			p = root;
			l = strlen(s);
			g = 1;
			for (int i = 0;i < l;i++){
				if (p->f) f = 0;
				if (p->c[s[i] - '0'] == 0){
					q = get();
					q->f = 0;
					q->c[0] = q->c[1] = 0;
					g = 0;
					p->c[s[i] - '0'] = q;
				}
				p = p->c[s[i] - '0'];
			}
			p->f = 1;
			if (g) f = 0;
			scanf("%s",s);
		}
		if (f) printf("Set %d is immediately decodable\n",te);else printf("Set %d is not immediately decodable\n",te);
	}
}