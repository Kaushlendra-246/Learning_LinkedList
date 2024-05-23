#include<iostream>
using namespace std;

//In c++ we can use both struct and class
//But in java only class
struct Node{
    int data;
    Node *next;

    Node(int val,Node *next1){
        data = val;
        next = next1;
    }    
};

int main(){
    Node x = Node(2,nullptr);
    cout<<x.data<<" "<<x.next<<endl;

    Node *y = &x;
    cout<<y->data<<" "<<y->next<<"\n";
    

    //Other Method

    //Node *y = new Node(2,NULL);
    //cout<<y->data<<" "<<y->next<<"\n";
}