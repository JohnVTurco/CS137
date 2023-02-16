#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct dlnode{
	int data;
	struct dlnode *next;
	struct dlnode *prev;

} dlnode;

typedef struct {
	dlnode *head;	//points to the first element otherwise NULL
	dlnode *tail;	//points to the last element otherwise NULL
	int len;	// number of elements
} ndlst;

//Pre: None
//Post: Creates a null list
struct ndlst *dlistCreate(void)
{
	ndlst *ret = malloc(sizeof(ndlst));
	ret->head = NULL;
	ret->tail = NULL;
	ret->len = 0;
	return ret;
}

//Pre: lst is a valid list 
//Post: Destroys the list
void dlistDestroy(ndlst *lst)
{
	dlnode *cur = lst->head;
    dlnode *next = NULL;

    while(cur){
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(lst);
}

//Pre: lst is valid
//Post: returns the number of elements in the list
int dlistLength(ndlst *lst)
{
	return lst->len;
}

//Pre: lst is a valid list with length of at least n>=1
//Post: nth item removed
void dlistRemoveElem(ndlst *lst, int n)
{
    dlnode *cur = lst->head;
    dlnode *prevNode = NULL;
    dlnode *nextNode = NULL;
    
    for(int i =1; i < n; i ++){
        cur = cur->next;
    }

    if(n == 1){
        if(n == lst->len){
            lst->head = NULL;
            lst->tail = NULL;
            lst->len = 0;
        }
        else{
            nextNode = cur->next;
            nextNode->prev = NULL;
            lst->head = nextNode;
        }
    }
    else{
        prevNode = cur->prev;
        if(n == lst->len){
            prevNode->next = NULL;
            lst->tail = prevNode;
        }
        else{
            nextNode = cur->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }

    }
    free(cur);
    lst->len = lst->len - 1;

}

// lst is a valid list
void dlistAddToFront(ndlst *lst, int elem)
{
	dlnode *newNode = malloc (sizeof(dlnode));
	newNode->data = elem;

    if(lst->len > 0){
        newNode->next = lst->head;
        lst->head->prev = newNode;
        newNode->prev = NULL;
        lst->head = newNode;
        if(lst->len == 1){
            lst->tail = newNode->next;
        }
    }
    else{
        lst->head = newNode;
        lst->tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    lst->len = lst->len + 1;
}

// lst is a valid list
void dlistAddToEnd(ndlst *lst, int elem)
{
    dlnode *newNode = malloc(sizeof(dlnode));
    newNode->data = elem;

    if(lst->len > 0){
        newNode->next = NULL;
        newNode->prev = lst->tail;
        lst->tail->next = newNode;
        lst->tail = newNode;
        if(lst->len == 1){
            lst->head = newNode->prev;
        }
    }
    else{
        lst->head = newNode;
        lst->tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    lst->len = lst->len + 1;
}

// Pre: lst is valid
// prints the items in the list from start to end.
// Do not submit
void dlistPrint(ndlst *lst)
{
	dlnode *node = lst->head;
	
	for (; node; node = node->next)
		printf("%d  ", node->data);
	printf("\n");
}


//Do not submit
void dlistPrintReverse(ndlst *lst)
{
	dlnode *node = lst->tail;
	for (; node; node = node->prev)
		printf("%d  ", node->data);
	printf("\n");
}

void swap(dlnode *node){
    int temp;
    temp = node->next->data;
    node->next->data = node->data;
    node->data = temp;
}


// lst is a valid list to be sorted in ascending order
void dlistSort(ndlst *lst)
{   
    dlnode *curr = lst->head;

    for(int i = 1; i <= lst->len; i++){
        curr = lst->head;
        for(int j = 1; j <= lst->len -i; j++){
            if(curr->next->data < curr->data){
                swap(curr);
            }
            curr = curr->next;
        }
    }    


}


// rotate the list n times to the left, assume, lst not empty
void dlistRotateLeft(ndlst *lst, int n)
{
	if(lst->len > 1){
        for(int i = 0 ; i < n; i++){
            dlnode *headNode = lst->head;
            dlnode *tailNode = lst->tail;
            lst->head = headNode->next;
            lst->head->prev = NULL;
            lst->tail = headNode;
            tailNode->next = headNode;
            headNode->prev = tailNode;
            headNode->next = NULL;
        }
    }
}

// rotate the list n times to the right, assume, lst not empty
void dlistRotateRight(ndlst *lst, int n)
{
    if(lst->len > 1){
        for(int i = 0; i < n; i++){
            dlnode *headNode = lst->head;
            dlnode *tailNode = lst->tail;
            lst->tail = tailNode->prev;
            lst->tail->next = NULL;
            lst->head = tailNode;
            tailNode->next = headNode;
            headNode->prev = tailNode;
            tailNode->prev = NULL;
        }
    }
	
}

int main(void)
{
	ndlst *lst1 = dlistCreate();
	assert(dlistLength(lst1) == lst1->len);
	assert(dlistLength(lst1) == 0);
	dlistAddToEnd(lst1, 10);
	dlistAddToFront(lst1, -20);
	dlistAddToFront(lst1, 0);
	dlistAddToEnd(lst1, 9);
	dlistAddToFront(lst1, -9);
	dlistAddToFront(lst1, 7);
	dlistAddToEnd(lst1, 40);
	assert(dlistLength(lst1) == lst1->len);
	assert(dlistLength(lst1) == 7);
	dlistPrint(lst1);
	dlistPrintReverse(lst1);

	dlistRemoveElem(lst1, 5);
	dlistRemoveElem(lst1, 1);
	dlistRemoveElem(lst1, 5);
	dlistAddToEnd(lst1, 100);
	assert(dlistLength(lst1) == lst1->len);
	assert(dlistLength(lst1) == 5);
	dlistPrint(lst1);
	dlistPrintReverse(lst1);
	dlistSort(lst1);
	dlistPrint(lst1);
	dlistRotateLeft(lst1, 2);
	dlistPrint(lst1);
	dlistRotateRight(lst1, 3);
	dlistPrint(lst1);
	dlistDestroy(lst1);

   
     printf("Reached");
	return 0;
}
