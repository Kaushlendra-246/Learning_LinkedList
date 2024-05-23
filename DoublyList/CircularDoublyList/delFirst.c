#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
}Node;

void addBefore(Node *tail,int data){
    Node *ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    Node *temp = tail->next;
    ptr->next = temp;
    ptr->prev = tail;
    tail->next = ptr;
    temp->prev = ptr;
}

Node* delFirst(Node *tail){
    Node *temp = tail->next;

    if(tail == NULL){
        return tail;
    }

    if(temp == tail){
        free(temp);
        tail = NULL;
        return tail;
    }

    else{
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);
    temp = NULL;
    return tail;
    }
}

int main(){
    Node *tail = malloc(sizeof(Node));
    tail->data = 15;
    tail->prev = tail;
    tail->next = tail;

    Node *ptr = malloc(sizeof(Node));
    ptr->data = 11;
    ptr->prev = NULL;
    ptr->next = NULL;

    ptr->next = tail;
    ptr->prev = tail;
    tail->next = ptr;
    tail->prev = ptr;

    addBefore(tail,13);
    addBefore(tail,18);
    addBefore(tail,20);

    ptr = tail->next;
    do{
       printf("%d ",ptr->data);
       ptr = ptr->next;
    }while(ptr != tail->next);
    printf("\n");

    tail = delFirst(tail);

    ptr = tail->next;
    do{
       printf("%d ",ptr->data);
       ptr = ptr->next;
    }while(ptr != tail->next);
    printf("\n");
    return 0;
}