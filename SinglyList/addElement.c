#include<stdio.h> // for -> NULL
typedef struct node {
    int data;
    struct node *link;
}Node;

Node* add(Node *ptr, int data){
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp; //Return Last node Address
}