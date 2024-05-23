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

int isPresent(Node *tail,int n){
    int position = 1;
    Node *ptr = tail->next;
    do{
        if(ptr->data == n) return position;
        ptr = ptr->next;
        position++;
    }while(ptr != tail->next);
    return -1;
}

int main(){
    Node *tail = malloc(sizeof(Node));
    tail->data = 5;
    tail->next = tail;

    addBefore(tail,15);
    addBefore(tail,8);
    addBefore(tail,12);

    Node *ptr = tail->next;
    do {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != tail->next);
    printf("\n");
    
    int element = 8;
    int n = isPresent(tail,element);
    if(n == -1) printf("%d is not present in list\n",element);
    else printf("%d is present in list at position %d\n",element,n);
    return 0;
}