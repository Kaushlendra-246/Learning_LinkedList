#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};

int main(){
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    //struct node *head = malloc(sizeof(struct node));
    
    head->data = 25;
    (*head).link = NULL;

    printf("%d\n",(*head).data);
    return 0;
}