#include <cstdio>
struct node{int key,size,prio,num;node *c[2];};
typedef node* tree;
node pool[300010];
tree root,null;
int a[300010],b[300010] = {0},n,m,x,k;
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
	x->size = 1;
	x->c[0] = x->c[1] = null;
	x->prio = Rand();
	x->key = key;
	x->num = 1;
	return x;
}
void Rotate(tree &x,int k){
	tree y = x->c[k];
	x->c[k] = y->c[!k];
	y->c[!k] = x;
	y->size = x->size;
	x->size = x->c[0]->size + x->c[1]->size + x->num;
	x = y;
}
void Insert(tree &x,int key){
	if (x == null){
		x = New(key);
		return;
	}
	if (x->key == key){
		++x->num;
		++x->size;
		return;
	}
	int k = (key > x->key);
	Insert(x->c[k],key);
	++x->size;
	if (x->prio < x->c[k]->prio) Rotate(x,k);
}
void Delete(tree& x,int key){
	if (x->key != key){
		Delete(x->c[key > x->key],key);
		--x->size;
	}
	else if (x->num > 1){
		--x->num;
		--x->size;
	}
	else if (x->c[0] == null) x = x->c[1];
	else if (x->c[1] == null) x = x->c[0];
	else{
		int k = x->c[0]->prio > x->c[1]->prio;
		Rotate(x,k);
		Delete(x->c[!k],key);
		--x->size;
	}
}
int Rank(tree x,int key){
	if (x == null) return 0;
	if (x->key == key) return x->c[0]->size + 1;
	if (x->key > key) return Rank(x->c[0],key);
	return x->c[0]->size + x->num + Rank(x->c[1],key);
}
int Key(tree x,int rank){
	if (x->c[0]->size >= rank) return Key(x->c[0],rank);
	if (x->c[0]->size + x->num >= rank) return x->key;
	return Key(x->c[1],rank - x->c[0]->size - x->num);
}
int Prev(tree x,int key){
	if (x == null) return 0;
	if (key <= x->key) return Prev(x->c[0],key);
	return max(x->key,Prev(x->c[1],key));
}
int Succ(tree x,int key){
	if (x == null) return 1e9;
	if (key >= x->key) return Succ(x->c[1],key);
	return min(x->key,Succ(x->c[0],key));
}
int main(){
	null = pool;
	null->size = 0;
	root = null;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= m;i++){
		scanf("%d",&x);
		b[x]++;
	}
	k = 0;
	for (int i = 1;i <= n;i++){
		Insert(root,a[i]);
		for (int j = 1;j <= b[i];j++){
			x = Key(root,++k);
			printf("%d\n",x);
		}
	}
}
