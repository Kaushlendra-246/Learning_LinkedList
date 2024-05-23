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
    return temp; //return last node Address
}

void insertAt(struct node *ptr, int position, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if(position >= 2) {
    position--;
    while(position != 1)
    {
        ptr = ptr->link;
        position--;
    }

    temp->link = ptr->link;
    ptr->link = temp;
    }
    else{
        printf("Wrong position\n");
    }
    
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 25;
    head->link = NULL;

    struct node *ptr = head;
    ptr = addAtEnd(ptr,12);
    ptr = addAtEnd(ptr,15);
    ptr = addAtEnd(ptr,20);
    ptr = addAtEnd(ptr,25);

    insertAt(head,3,18);
    insertAt(head,6,40);

    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}