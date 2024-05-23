#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
}Node;

int main(){
    Node *head = malloc(sizeof(Node));
    head->prev = NULL;
    head->data = 12;
    head->next = NULL;

    Node *ptr = malloc(sizeof(Node));
    ptr->prev = NULL;
    ptr->data = 15;
    ptr->next = NULL;

    head->next = ptr;
    ptr->prev = head;

    Node *ptr2 = malloc(sizeof(Node));
    ptr2->prev = NULL;
    ptr2->data = 9;
    ptr2->next = NULL;

    ptr->next = ptr2;
    ptr2->prev = ptr;

    printf("%d ",head->data);
    printf("%d ",ptr->prev->data);
    printf("%d ",ptr2->prev->prev->data);
    printf("\n");

    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    return 0;
}