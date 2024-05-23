#include<stdio.h>
#include<stdlib.h>
#include"addElement.c"
int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 28;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add(ptr,12);
    ptr = add(ptr,25);
    ptr = add(ptr,35);

    ptr = head;
    printf("List : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    struct node *temp = head->link;
    head->link = temp->link;
    temp->link = head;
    head = temp;

    ptr = head;
    printf("After Interchanging first two Element of List : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}