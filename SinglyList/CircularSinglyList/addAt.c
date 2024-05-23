#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

Node *addAfter(Node *tail,int data){
    Node *ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = tail->next;
    tail->next = ptr;
    tail = tail->next;
    return tail;
}

Node *addAt(Node *tail,int pos,int data){
    Node *ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    Node *temp = tail->next;
    while(pos > 2){
        temp = temp->next;
        pos--;
    }
    
    ptr->next = temp->next;
    temp->next = ptr;

    if(temp == tail){
        tail = tail->next;
    }
    return tail;
}

int main(){
    Node *tail = malloc(sizeof(Node));
    tail->data = 5;
    tail->next = tail;

    tail = addAfter(tail,10);
    tail = addAfter(tail,20);
    tail = addAfter(tail,25);

    tail = addAt(tail,4,13);

    Node *ptr = tail->next;
    do {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != tail->next);
    return 0;
}