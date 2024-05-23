#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
}Node;

void addBefore(Node *tail,int data){
    Node *ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    Node *temp = tail->next;
    ptr->next = temp;
    ptr->prev = tail;
    tail->next = ptr;
    temp->prev = ptr;
}

void delAt(Node *tail,int pos){
    Node *temp = tail->next;
    Node *temp2 = NULL;
    while(pos > 1){
        temp2 = temp;
        temp = temp->next;
        pos--;
    }

    temp2->next = temp->next;
    temp->next->prev = temp;
    free(temp);
    temp = NULL;
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

    addBefore(tail,13);
    addBefore(tail,18);
    addBefore(tail,20);

    delAt(tail,3);

    ptr = tail->next;
    do{
       printf("%d ",ptr->data);
       ptr = ptr->next;
    }while(ptr != tail->next);
    printf("\n");
    return 0;
}