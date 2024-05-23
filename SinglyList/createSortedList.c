#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

Node *add(Node *head,int data){
    Node *ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    int key = ptr->data;
    if(head == NULL || key < head->data){
        ptr->next = head;
        head = ptr;
        return head;
    }
    else{
        Node *temp = head;
        while(temp->next != 0 && temp->next->data < key){
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
        return head;
    }
}

int main(){
    Node *head = malloc(sizeof(Node));
    head->data = 24;
    head->next = NULL;

    head = add(head,12);
    head = add(head,28);
    head = add(head,26);

    Node *ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}