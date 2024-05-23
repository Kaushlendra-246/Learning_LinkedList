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

// void delNode(struct node *head){
//     struct node *ptr = head;
//     struct node *ptr2 = head;

//     while(ptr->link != NULL){
//         ptr2 = ptr;
//         ptr = ptr->link;
//     }
//     ptr2->link = NULL;

//     free(ptr);
//     ptr = NULL;
// }

void delNode(struct node *head){
    struct node *ptr = head;

    while(ptr->link->link != 0){
        ptr = ptr->link;
    }

    free(ptr->link);
    ptr->link = NULL;
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
    
    delNode(head);
    printf("\nAfter deleting Last node :\n");
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}