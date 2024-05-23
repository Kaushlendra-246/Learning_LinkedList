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

Node* delHead(Node *head){
    Node *ptr = head;

    //Method 1

    // head->next->prev = NULL;
    // head = head->next;
    // free(ptr);
    // ptr = NULL;

    //Method 2

    // head = head->next;
    // free(ptr);
    // ptr = NULL;
    // head->prev = NULL;

    //Method 3

    head = head->next;
    free(head->prev);
    head->prev = NULL;

    return head;
}

int main(){
    Node *head = malloc(sizeof(Node));
    head->prev = NULL;
    head->data = 4;
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

    head = delHead(head);
    printf("New List : ");
    ptr = head;
    while(ptr != 0){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}