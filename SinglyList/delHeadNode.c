#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};

struct node* addAtEnd(struct node *ptr,int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

struct node* delHead(struct node *head){
    struct node *ptr = head;
    head = head->link;
    free(ptr);
    ptr = NULL;
    return head;
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 3;
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
    
    ptr = delHead(head);
    printf("\nAfter deleting head :\n");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}