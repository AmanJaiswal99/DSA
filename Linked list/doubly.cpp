#include <iostream>
using namespace std;

class Node{

    public:
    int key;
    int data;
    Node* next;
    Node* previous;

    Node(){
        key=0;
        data=0;
        next=NULL;
        previous=NULL;
    }

    Node(int k, int d){
        key =k;
        data=d;
    }
};

class Doubly{

    public:
    Node* head;

    Doubly(){
        head=NULL;
    }

    Doubly(Node*n){
        head=n;
    }

    //check if node exists

    Node* nodeExist(int k){
        Node* temp;
        Node* ptr=head;
        while(ptr!=NULL){
            if(ptr->key==k){
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    // append a node to the end

    void appendNode(Node*n){
        if(nodeExist(n->key)!=NULL){
            cout <<"node already exists" <<endl;
        }else{
             Node*ptr = head;
             while(ptr->next!=NULL){
                 ptr = ptr->next;
             }
             ptr->next=n;
             n->previous = ptr;
             cout << "node appeneded" <<endl;
        }
    }
};


int main(){

    return 0;
}