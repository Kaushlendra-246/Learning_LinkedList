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

void addAt(Node *head,int pos,int data){
    Node *ptr = malloc(sizeof(Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    Node *temp = head;
    Node *temp2 = head;
    if(pos == 1) printf("Use insert At begining\n");
    else{
        while(pos != 1){
        temp = temp2;
        temp2 = temp2->next;
        pos--;
    }
    if(temp->next == NULL){
        temp->next = ptr;
        ptr->prev = temp;
    }
    else{
        temp->next = ptr;
        ptr->next = temp2;
        temp2->prev = ptr;
        ptr->prev = temp;
    }
    }
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

    addAt(head,4,10);
    printf("New List : ");
    ptr = head;
    while(ptr != 0){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}