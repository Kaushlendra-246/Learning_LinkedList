#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int coeff;
    int expo;
    struct node *next;
}Node;

int main(){
    Node *head = malloc(sizeof(Node));
    head->coeff = 3;
    head->expo = 2;
    head->next = NULL;

    Node *ptr = malloc(sizeof(Node));
    ptr->coeff = -2;
    ptr->expo = 1;
    ptr->next = NULL;

    head->next = ptr;

    Node *ptr2 = malloc(sizeof(Node));
    ptr2->coeff = 1;
    ptr2->expo = 0;
    ptr2->next = NULL;

    ptr->next = ptr2;

    printf("Polynomial terms : \n");
    ptr = head;
    while(ptr != NULL){
        printf("Coefficent %d and ",ptr->coeff);
        printf("Exponent %d\n",ptr->expo);
        ptr = ptr->next;
    }
}
