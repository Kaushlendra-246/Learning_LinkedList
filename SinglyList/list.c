#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};

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

    current = malloc(sizeof(struct node));
    current->data = 30;
    current->link = NULL;
    //Connect third node to fourth
    head->link->link->link = current;

    //Display list
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}