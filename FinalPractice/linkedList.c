#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    int data;
};

struct list{
    struct node *head;
    int len;
};

struct list *create(void){
    struct list *ret = malloc(sizeof(struct list));
    ret->head = NULL;
    ret->len = 0;
}

void destroy