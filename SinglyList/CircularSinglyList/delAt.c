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

Node *delAt(Node *tail, int pos){
    Node *temp = tail->next;
    if(pos == 1){
        tail->next = temp->next;
        free(temp);
        temp = NULL;
        return tail;
    }
    else {
    while(pos > 2){
        temp = temp->next;
        pos--;
    }
    Node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    temp2 = NULL;
    return tail;
    }
}

int main(){
    Node *tail = malloc(sizeof(Node));
    tail->data = 5;
    tail->next = tail;

    addBefore(tail,15);
    addBefore(tail,8);
    addBefore(tail,12);
    addBefore(tail,25);

    printf("List : ");
    Node *ptr = tail->next;
    do {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != tail->next);
    printf("\n");

    tail = delAt(tail,1);
    Node *ptr2 = tail->next;
    printf("New List : ");
    do {
        printf("%d ",ptr2->data);
        ptr2 = ptr2->next;
    }while(ptr2 != tail->next);
    return 0;
}