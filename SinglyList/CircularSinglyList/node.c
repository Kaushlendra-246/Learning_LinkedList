#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}Node;
int main(){
    Node *tail = malloc(sizeof(Node));
    tail->data = 5;
    tail->next = tail;

    printf("%d ",tail->data);
    printf("%p ",tail);
    printf("%p ",tail->next);
}