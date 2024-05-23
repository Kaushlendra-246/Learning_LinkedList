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

void delFirst(Node *tail){
    Node *temp = tail->next;
    tail->next =temp->next;
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

    delFirst(tail);
    Node *ptr2 = tail->next;
    printf("New List : ");
    do {
        printf("%d ",ptr2->data);
        ptr2 = ptr2->next;
    }while(ptr2 != tail->next);
    return 0;
}