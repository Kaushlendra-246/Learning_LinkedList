//Not Work when we want to delete last node
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int value;
    struct node *next;
}Node;

Node* add(Node *ptr, int data){
    Node *temp = malloc(sizeof(Node));
    temp->value = data;
    temp->next = NULL;

    ptr->next = temp;
    return temp; //Return Last node Address
}

void delNode(Node *head,int pos){
    Node *ptr = head;
    while(pos != 1){
        ptr = ptr->next;
        pos--;
    }
    
    Node *temp = ptr->next;
    ptr->value = temp->value;
    ptr->next = temp->next;
    free(temp);
    temp = NULL;
}

int main(){
    Node *head = malloc(sizeof(Node));
    head->value = 23;
    head->next = NULL;

    Node *ptr = head;
    ptr = add(ptr,25);
    ptr = add(ptr,28);
    ptr = add(ptr,15);
    ptr = add(ptr,18);
    ptr = add(ptr,9);
    ptr = add(ptr,7);

    ptr = head;
    printf("List : ");
    while(ptr != NULL){
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");

    delNode(head,3);
    ptr = head;
    printf("After deleting node,List : ");
    while(ptr != NULL){
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}