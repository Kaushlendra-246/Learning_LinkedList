#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};

struct node* add(struct node *ptr, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp; //Return Last node Address
}

struct node* reverse(struct node *head){
    struct node *prev = NULL;
    struct node *next = NULL;

    while(head != NULL){
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 28;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add(ptr,12);
    ptr = add(ptr,15);
    ptr = add(ptr,20);
    ptr = add(ptr,24);

    printf("List : ");
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    head = reverse(head);
    printf("Reversed List : ");
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}