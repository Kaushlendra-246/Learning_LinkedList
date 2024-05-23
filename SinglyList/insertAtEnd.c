//Time Complexity - O(1)
//Optimal Code
//Without Traversal
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

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 25;
    head->link = NULL;

    struct node *ptr = head;
    ptr = addAtEnd(ptr,12);
    ptr = addAtEnd(ptr,15);
    ptr = addAtEnd(ptr,20);

    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}