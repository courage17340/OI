#include <cstdio>
struct node{int key,prio;node *c[2];};
typedef node* tree;
node pool[100010];
tree root,null;
int min(int a,int b){
	return a < b ? a : b;
}
int max(int a,int b){
	return a > b ? a : b;
}
inline int Rand(){
	static int seed = 1542;
	return seed = int(seed * 48271ll % 2147483647 );
}
tree New(int key = 0){
	static int p = 0;
	tree x = &pool[++p];
	x->c[0] = x->c[1] = null;
	x->prio = Rand();
	x->key = key;
	return x;
}
void Rotate(tree &x,int k){
	tree y = x->c[k];
	x->c[k] = y->c[!k];
	y->c[!k] = x;
	x = y;
}
void Insert(tree &x,int key){
	if (x == null){
		x = New(key);
		return;
	}
	if (x->key == key){
		return;
	}
	int k = (key > x->key);
	Insert(x->c[k],key);
	if (x->prio < x->c[k]->prio) Rotate(x,k);
}

int Prev(tree x,int key){
	if (x == null) return -1e9;
	if (key == x->key) return key;
	if (key < x->key) return Prev(x->c[0],key);
	return max(x->key,Prev(x->c[1],key));
}
int Succ(tree x,int key){
	if (x == null) return 1e9;
	if (key == x->key) return key;
	if (key > x->key) return Succ(x->c[1],key);
	return min(x->key,Succ(x->c[0],key));
}
int n,ans,x;
int main(){
	null = pool;
	root = null;
	scanf("%d",&n);
	ans = 0;
	if (n) scanf("%d",&ans);
	Insert(root,ans);
	for (int i = 2;i <= n;i++){
		if (scanf("%d",&x) == EOF) x = 0;
		ans += min(x - Prev(root,x),Succ(root,x) - x);
		Insert(root,x);
	}
	printf("%d\n",ans);
}
