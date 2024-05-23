#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void addAtBeg(struct node **head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = *head;
    *head = temp;
}

// struct node* addAtBeg(struct node *head,int data){
//     struct node *temp = malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;

//     temp->link = head;
//     head = temp;
//     return head;
// }
int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 37;
    ptr->link = NULL;
    head->link = ptr;
    //Method 1
    //Pass by value
    //Here We pass content of head(Address of first node), not the address of head
    //head = addAtBeg(head,25);

    //Method 2
    //Pass by Ref
    addAtBeg(&head,25);

    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}