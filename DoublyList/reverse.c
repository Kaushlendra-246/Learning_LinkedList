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

Node *reverse(Node *head){
    Node *ptr = head;
    Node *ptr2 = ptr->next;

    ptr->next = NULL;
    ptr->prev = ptr2;

    while(ptr2 != NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr;
        ptr = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr;
    return head;
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
    ptr = addAtEnd(ptr,10);

    printf("List : ");
    ptr = head;
    while(ptr != 0){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    head = reverse(head);
    printf("Reversed List : ");
    ptr = head;
    while(ptr != 0){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}