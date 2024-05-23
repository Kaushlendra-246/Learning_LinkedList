#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
}Node;

Node *addAtEnd(Node *head,int data){
    Node *ptr = malloc(sizeof(Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    head->next = ptr;
    ptr->prev = head;
    return ptr;
}

Node *createList(Node *head){
    int n,value;
    printf("Enter number of node : ");
    scanf("%d",&n);
    
    if(n <= 0) return head;

    printf("Enter Element 1 : ");
    scanf("%d",&value);
    head->prev = NULL;
    head->data = value;
    head->next = NULL;

    Node *temp = head;
    for(int i=2; i<=n; i++){
        printf("Enter Element %d : ",i);
        scanf("%d",&value);
        temp = addAtEnd(temp,value);
    }
    return head;
}

int main(){
    Node *head = malloc(sizeof(Node));
    head = createList(head);
    Node *ptr = head;

    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}