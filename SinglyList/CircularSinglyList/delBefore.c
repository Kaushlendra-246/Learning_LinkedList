#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}Node;

void addBefore(Node *tail,int data){
    Node *ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = tail->next;
    tail->next = ptr;
}

void delBefore(Node *tail){
    Node *ptr = tail->next;
    while(ptr->next->next != tail){
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = tail;
    free(temp);
    temp = NULL;
}

int main(){
    Node *tail = malloc(sizeof(Node));
    tail->data = 5;
    tail->next = tail;

    addBefore(tail,15);
    addBefore(tail,8);
    addBefore(tail,12);

    printf("List : ");
    Node *ptr = tail->next;
    do {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != tail->next);
    printf("\n");

    delBefore(tail);
    Node *ptr2 = tail->next;
    printf("New List : ");
    do {
        printf("%d ",ptr2->data);
        ptr2 = ptr2->next;
    }while(ptr2 != tail->next);

    return 0;
}