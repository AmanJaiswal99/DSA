#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;

    Node(){
        key =0;
        data = 0;
        next=NULL;
    }
    Node(int k, int d){
        key = k;
        data = d;
    }
};

class SinglyLinkedList{
    public:
    Node* head;

    SinglyLinkedList(){
        head = NULL;
    }
    SinglyLinkedList(Node *n){
        head=n;
    }
    //check if node exists using key value
    Node* nodeExist(int k){
        Node* temp = NULL;
        Node* ptr = head;
        while(ptr!=NULL){
            if(ptr->key==k){
                temp = ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    //append node to the list
    void appendNode(Node *n){
        if(nodeExist(n->key)!=NULL){
            cout << "node already exists with that key value" << endl;
        }else{
            if(head==NULL){ 
                head = n;
                cout << "node appended" << endl;
            }else{
                Node *ptr = head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=n;
                 cout << "node appended" << endl;
            }
        }
    };

    //prepend node- Attach a node to the start

    void prepend(Node *n){
        if(nodeExist(n->key)!=NULL){
            cout <<"node already exist with that value" <<endl;
        }else{
            n->next=head;
            head=n;
            cout << "node prepended" <<endl;
        }
    }
    
    // insert a node after a particular node in the list
    void insertNodeAfter(int k,Node *n){
        Node *ptr = nodeExist(k);
        if(ptr==NULL){
            cout <<"no node exist with that key value" <<endl;
        }else{
            if(nodeExist(n->key)!=NULL){
            cout <<"node already exist with that key value" <<endl;
        }else{
            n->next=ptr->next;
            ptr->next=n;
        }
        }
    }
};



int main(){


    return 0;
}