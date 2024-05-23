#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int value;
    struct node *next;
}Node;

Node* add(Node *ptr, int data){
    Node *temp = malloc(sizeof(Node));
    temp->value = data;
    temp->next = NULL;

    ptr->next = temp;
    return temp; //Return Last node Address
}

void rearreng(Node *list){
    Node *ptr = list;
    Node *ptr2 = list->next;
    if(!list || !list->next) return; //(list != NULL || list->next != NULL)
    int temp;
    while(ptr2){
        temp = ptr2->value;
        ptr2->value = ptr->value;
        ptr->value = temp;

        ptr = ptr2->next;
        ptr2 = ptr?ptr->next:0;
    }
}

int main(){
    Node *head = malloc(sizeof(Node));
    head->value = 23;
    head->next = NULL;

    Node *ptr = head;
    ptr = add(ptr,25);
    ptr = add(ptr,28);
    ptr = add(ptr,15);
    ptr = add(ptr,18);
    ptr = add(ptr,9);
    ptr = add(ptr,7);

    ptr = head;
    printf("List : ");
    while(ptr != NULL){
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");

    rearreng(head);  //function call
    ptr = head;
    printf("List : ");
    while(ptr != NULL){
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}