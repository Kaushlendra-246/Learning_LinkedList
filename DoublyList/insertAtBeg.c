#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
}Node;

Node* add(Node *ptr,int data){
    Node *temp = malloc(sizeof(Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    ptr->next = temp;
    temp->prev = ptr;
    return temp;
}

Node* addAtBeg(Node* head,int data){
    Node *temp = malloc(sizeof(Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

int main(){
    Node *head = malloc(sizeof(Node));
    head->prev = NULL;
    head->data = 12;
    head->next = NULL;

    printf("%d\n",head->data);

    Node *ptr = head;
    ptr = add(ptr,5);
    printf("%d ",ptr->data);
    printf("%d\n",ptr->prev->data);
    ptr = add(ptr,15);
    printf("%d ",ptr->data);
    printf("%d ",ptr->prev->data);
    printf("%d\n",ptr->prev->prev->data);
    ptr = add(ptr,20);

    printf("List : ");
    ptr = head;
    while(ptr != 0){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    head = addAtBeg(head,10);
    printf("New List : ");
    ptr = head;
    while(ptr != 0){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}