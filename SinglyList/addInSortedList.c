#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};

struct node* addAtEnd(struct node *ptr, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp; //pass last node Address
}

struct node* add(struct node* head,int data){
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;

    int key = ptr->data;
    if(head == NULL || key < head->data){
        ptr->link = head;
        head = ptr;
        return head;
    }
    else{
        struct node* temp = head;
        while(temp->link != NULL && temp->link->data < key){
            temp = temp->link; 
        }
        ptr->link = temp->link;
        temp->link = ptr;
        return head;
    }
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 12;
    head->link = NULL;

    struct node *ptr = head;
    ptr = addAtEnd(ptr,15);
    ptr = addAtEnd(ptr,20);
    ptr = addAtEnd(ptr,25);

    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    head = add(head,18);

    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}