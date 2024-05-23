#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //For head node
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
 
    //For other node
    Node(int data,Node* next1){
        this->data = data;
        next = next1;
    }
};

Node* convertArr2LL(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i=1; i<arr.size(); i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* removeVal(Node* head,int el){
    if(head == NULL) return head;
    if(head->data == el){
        Node *temp = head;
        head = head->next;
        delete temp;
        //free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {2,4,1,6,8,5,3,9};
    Node *head = convertArr2LL(arr)

    Node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;

    Node *newHead = removeVal(head,1);

    Node *pt = newHead;
    while(pt != NULL){
        cout<<pt->data<<" ";
        pt = pt->next;
    }
    cout<<endl;
}