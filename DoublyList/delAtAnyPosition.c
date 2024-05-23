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
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

Node *delAt(Node *head,int pos){
    Node *temp = head;
    if(pos == 1) {
       head = delHead(head);
       return head;
    }

    else {
    while(pos > 1){
        temp = temp->next;
        pos--;
    }
    Node *temp2 = temp->prev;

    
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    temp = NULL;
    return head;
    }
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
    ptr = addAtEnd(ptr,25);

    printf("List : ");
    ptr = head;
    while(ptr != 0){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    head = delAt(head,3);
    printf("New List : ");
    ptr = head;
    while(ptr != 0){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}