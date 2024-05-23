//Time Complexity - O(n)
//Traversing list
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};

void addAtEnd(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    struct node *ptr = head;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 25;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 10;
    current->link = NULL;
    //Connect first node to second
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    //Connect second node to third
    head->link->link = current;

    addAtEnd(head,35);

    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}