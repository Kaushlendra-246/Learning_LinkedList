#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
}Node;

Node* addAfter(Node *tail,int data){
    Node *ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    Node *temp = tail->next;
    ptr->next = temp;
    ptr->prev = tail;
    tail->next = ptr;
    temp->prev = ptr;
    tail = ptr;
    return tail;
}

int main(){
    Node *tail = malloc(sizeof(Node));
    tail->data = 15;
    tail->prev = tail;
    tail->next = tail;

    Node *ptr = malloc(sizeof(Node));
    ptr->data = 11;
    ptr->prev = NULL;
    ptr->next = NULL;

    ptr->next = tail;
    ptr->prev = tail;
    tail->next = ptr;
    tail->prev = ptr;

    tail = addAfter(tail,13);
    tail = addAfter(tail,18);
    tail = addAfter(tail,20);

    ptr = tail->next;
    do{
       printf("%d ",ptr->data);
       ptr = ptr->next;
    }while(ptr != tail->next);
    printf("\n");
    return 0;
}