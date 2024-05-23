#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node* addAtEnd(struct node* ptr, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

void delPosition(struct node **head, int pos){
    struct node *ptr = *head;
    struct node *ptr2 = *head;

    if(*head == NULL){
        printf("\nList is Already empty\n");
    }
    else if(pos == 1){
        *head = ptr->link;
        free(ptr);
        ptr = NULL;
    }
    else {
    while(pos != 1){
        ptr = ptr2;
        ptr2 = ptr2->link;
        pos--;
    }

    ptr->link = ptr2->link;
    free(ptr2);
    ptr2 = NULL;
    }
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 20;
    head->link = NULL;

    struct node *ptr = head;
    ptr = addAtEnd(ptr,8);
    ptr = addAtEnd(ptr,5);
    ptr = addAtEnd(ptr,13);
    ptr = addAtEnd(ptr,16);

    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }

    delPosition(&head,1);

    printf("\nAfter deleting node :\n");
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}