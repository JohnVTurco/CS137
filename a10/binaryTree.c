#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct bstnode {
	int item;
	struct bstnode *left;
	struct bstnode *right;
};

struct bst {
	struct bstnode *root;
	int count;
};

struct bst *bst_create(void)
{
	struct bst *t = malloc(sizeof(struct bst));
	t->root = NULL;
	t->count = 0;
	return t;
}

void destroy(struct bstnode *node)
{
	if (node != NULL)
	{
		destroy(node->left);
		destroy(node->right);
		free(node);
	}
}

void bst_destroy(struct bst *t)
{
	destroy(t->root);
	free(t);
}

int itemSearch(struct bstnode *n, int val){
    if(n->item == val){
        return 1;
    }
    if(val > n->item){
        if(n->right){
            return itemSearch(n->right, val);
        }
        else{
            return 0;
        }
    }
    else{
        if(n->left){
            return itemSearch(n->left, val);
        }
        else{
            return 0;
        }

    }
}

int bst_search(struct bst *t, int val)
{
        return itemSearch(t->root, val);
}

void insert(int num, struct bstnode *n){
    if(num > n->item){
        if(n->right){
            insert(num, n->right);
        }
        else{
            struct bstnode *l1 = malloc(sizeof(struct bstnode));
            l1->item = num;
            l1->left = NULL;
            l1->right = NULL;
            n->right = l1;
        }
    }
    else{
        if(n->left){
            insert(num, n->left);
        }
        else{
            struct bstnode *l2 = malloc(sizeof(struct bstnode));\
            l2->item = num;
            l2->right = NULL;
            l2->left = NULL;
            n->left = l2;
        }
    }
}

void bst_insert(int num, struct bst *t)
{
    if(t->count == 0){
        struct bstnode *h = malloc(sizeof(struct bstnode));
        h->item = num;
        h->left = NULL;
        h->right = NULL;
        t->root = h;
        t->count += 1;
    }
    else if(!bst_search(t, num)){
        insert(num, t->root);
        t->count+=1;
    }
	
}

void print(struct bstnode *node)
{
	if (node)
	{
		print(node->left);
		printf("%d ", node->item);
		print(node->right);
	}
}

void bst_print(struct bst *t)
{
	if (t->root)
	{
		print(t->root);
		printf("\n");
	}
}

int min(struct bstnode *n){
    if(n->left){
        return min(n->left);
    }
    else{
        return n->item;
    }
}

int bst_min(struct bst *t)
{
	return min(t->root);
}

int max(struct bstnode *n){
    if(n->right){
        return max(n->right);
    }
    else{
        return n->item;
    }
}

int bst_max(struct bst *t)
{
    if(t->root == NULL){
        return -1;
    }
    else{
        return max(t->root);
    }
}

int height(struct bstnode *n){
    if(n->left == NULL && n->right ==NULL){
        return 0;
    }
    int leftTree = 0, rightTree = 0;
    if(n->left){
        leftTree = 1 + height(n->left);
    }
    if(n->right){
        rightTree = 1 + height(n->right);
    }

    if(leftTree > rightTree){
        return leftTree;
    }
    else{
        return rightTree;
    }
    
}

int bst_height(struct bst *t)
{
    return height(t-> root);
}


// int main(void)
// {
// 	//public test order matters
// 	struct bst *tree = bst_create();
// 	bst_insert(100, tree);
// 	bst_insert(150, tree);
// 	bst_insert(78, tree);
// 	bst_insert(88, tree);
// 	assert(bst_min(tree) == 78);
// 	assert(bst_max(tree) == 150);
// 	bst_print(tree);
// 	bst_insert(-130, tree);
// 	assert(tree->count == 5);
// 	bst_insert(-130, tree);
// 	assert(tree->count == 5);
// 	bst_print(tree);
// 	assert(bst_search(tree, 100));
// 	assert(!bst_search(tree, 90));
// 	assert(bst_height(tree) == 2);

// // continue with secret tests.. order matters
// 	bst_insert(120, tree);
// 	bst_insert(113, tree);
// 	bst_insert(-60, tree);
// 	bst_insert(90, tree);
// 	bst_insert(190, tree);
// 	bst_print(tree);
// 	assert(bst_min(tree) == -130);
// 	assert(bst_max(tree) == 190);
// 	assert(tree->count == 10);
// 	assert(bst_height(tree) == 3);
// 	bst_destroy(tree);

// 	struct bst *tr = bst_create();
// 	bst_insert(100, tr);
// 	bst_insert(90, tr);
// 	bst_insert(80, tr);
// 	assert(bst_min(tr) == 80);
// 	assert(bst_max(tr) == 100);
// 	assert(tr->count == 3);
// 	bst_print(tr);
// 	assert(bst_height(tr) == 2);
// 	bst_destroy(tr);

// 	struct bst *tr2 = bst_create();
// 	bst_insert(100, tr2);
// 	bst_insert(190, tr2);
// 	bst_insert(280, tr2);
// 	bst_insert(300, tr2);
// 	bst_insert(490, tr2);
// 	bst_insert(580, tr2);
// 	assert(bst_min(tr2) == 100);
// 	assert(bst_max(tr2) == 580);
// 	assert(tr2->count == 6);
// 	assert(bst_height(tr2) == 5);
// 	bst_print(tr2);
// 	bst_destroy(tr2);

// 	struct bst *tr3 = bst_create();
// 	bst_insert(100, tr3);
// 	assert(bst_min(tr3) == 100);
// 	assert(bst_max(tr3) == 100);
// 	assert(tr3->count == 1);
// 	assert(bst_height(tr3) == 0);
// 	bst_print(tr3);
// 	bst_destroy(tr3);

// }

