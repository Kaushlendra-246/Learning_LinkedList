#include<stdio.h>
#include<stdlib.h>
#include"addElement.c"

int isSorted(Node *ptr){
    // In case of ||, if first true then second is not check
    // In case of &&, if first false then second is not check
    return ((ptr == NULL) || (ptr->link == NULL) || ((ptr->data <= ptr->link->data) && (isSorted(ptr->link))));
}

int main(){
    Node *head = malloc(sizeof(Node));
    head->data = 22;
    head->link = NULL;

    Node *ptr = head;
    ptr = add(ptr,25);
    ptr = add(ptr,28);
    ptr = add(ptr,32);
    ptr = add(ptr,15);
    ptr = add(ptr,35);

    int temp = isSorted(head);
    if(temp == 1) printf("List is Sorted\n");
    else printf("List is Unsorted\n");

    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}