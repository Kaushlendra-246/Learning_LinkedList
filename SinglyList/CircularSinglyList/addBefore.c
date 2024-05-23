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

int main(){
    Node *tail = malloc(sizeof(Node));
    tail->data = 5;
    tail->next = tail;

    addBefore(tail,15);
    addBefore(tail,8);
    addBefore(tail,12);

    //traversing Circular list
    Node *ptr = tail->next;
    //A Use of do-while loop
    do {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != tail->next);
    return 0;
}