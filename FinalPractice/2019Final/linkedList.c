#include <stdio.h>
#include <stdlib.h>

typedef struct llnode {
    int data;
    struct llnode *next;
} llnode;

typedef struct ll {
    llnode *head;
} ll;


ll *generateList(int n){
    ll *start = malloc(sizeof(ll));
    llnode *next = NULL;

    for(int i = n; i >= 0; i--){
        llnode *node = malloc(sizeof(llnode));
        node->next = next;
        node->data = i;
        next = node;
    }
    start->head = next;
    return start;

}



void llPrint(ll *l) {
for(llnode *cur = l->head; cur; cur=cur->next) printf("%d->", cur->data);
printf("NULL");
}
int main() {
ll *myList = generateList(5);
llPrint(myList); // prints "0->1->2->3->4->5->NULL"
}