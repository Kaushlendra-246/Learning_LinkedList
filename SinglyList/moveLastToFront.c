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

Node *move(Node *head){
    Node *ptr = NULL, *ptr2 = head;
    if(head == NULL || head->next == NULL){
        return head;
    }
    while(ptr2->next != NULL){
        ptr = ptr2;
        ptr2 = ptr2->next;
    }

    ptr->next = NULL;
    ptr2->next = head;
    head = ptr2;
    return head;
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

    ptr = head;
    printf("List : ");
    while(ptr != NULL){
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");

    head = move(head);
    ptr = head;
    printf("New List : ");
    while(ptr != NULL){
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}