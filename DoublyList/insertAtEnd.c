#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
}Node;

Node* addAtEnd(Node *ptr,int data){
    Node *temp = malloc(sizeof(Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    ptr->next = temp;
    temp->prev = ptr;
    return temp;
}

int main(){
    Node *head = malloc(sizeof(Node));
    head->prev = NULL;
    head->data = 12;
    head->next = NULL;

    Node *ptr = head;
    ptr = addAtEnd(ptr,5);
    ptr = addAtEnd(ptr,15);
    ptr = addAtEnd(ptr,20);

    printf("List : ");
    ptr = head;
    while(ptr != 0){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}