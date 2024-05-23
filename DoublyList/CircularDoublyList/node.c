#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
}Node;
int main(){
    Node *tail = malloc(sizeof(Node));
    tail->data = 15;
    tail->prev = tail;
    tail->next = tail;

    printf("%d ",tail->data);
    printf("%p ",tail->prev);
    printf("%p ",tail);
    printf("%p ",tail->next);
}