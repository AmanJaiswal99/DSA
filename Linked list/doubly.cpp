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
        Node* temp =NULL;
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
            cout <<"node already exists with that key" <<endl;
        }else{
            if(head==NULL){
                head =n;
                cout << "node appended as head node" <<endl; 
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
    }

    // prepend node

    void prepend(Node*n){
        if(nodeExist(n->key)!=NULL){
            cout << "node already exists with that key" << endl;
        }else{
            if(head==NULL){
                head=n;
                cout << "node prepended" << endl;
            }
            else{
            head->previous=n;
            n->next=head;
            head = n;
            cout << "node prepended" <<endl;
            }
        }
    }

    //insert node after a key

    void insertNode(int k,Node*n){
        Node*ptr = nodeExist(k);
        if(ptr==NULL){
            cout << "no such node exists" << endl;
        }else{
            if(nodeExist(n->key)!=NULL){
                cout << "a node with that key already exits" <<endl;
            }else{
                Node *nextNode = ptr->next;
                if(nextNode==NULL){
                 ptr->next=n;
                 n->previous=ptr;
                 cout << "node inserted" <<endl;   
                }else{
                    ptr->next=n;
                    n->next=nextNode;
                    nextNode->previous=n;
                    n->previous=ptr;
                    cout << "node inserted" <<endl;

                }
                
            }
        }
    }

    // delete a node by key value
    void deleteNode(int k){
        Node*ptr=nodeExist(k);
        if(ptr==NULL){
            cout << "no node exists with that key value" <<endl;
        }else{
            if(head==NULL){
                cout << "Doubly linked list in empty" <<endl;
            }else if(head!=NULL){
                if(head->key==k){
                    head=head->next;
                    cout << "node deleted" <<endl;
                }else{
                     Node* prev = ptr->previous;
                    Node* nextNode = ptr->next;
                    
                    if(nextNode==NULL){
                        prev->next=NULL;
                        cout <<"node deleted" <<endl;
                    }else{
                    prev->next=nextNode;
                    nextNode->previous=prev;
                    cout << "node deleted" <<endl;
                    }
                   
                  
                }
            }
        }
    }

    // update node
    void updateNode(int k,int d){
        Node*ptr = nodeExist(k);
        if(ptr==NULL){
            cout << "no such node exists"<<endl;;
        }else{
            ptr->data=d;
            cout << "node data updated" <<endl;;
        }
    }

    //print all data

    void printNode(){
        if(head==NULL){
            cout << "no nodes are there" <<endl;
        }else{
            Node*temp = head;
            while(temp!=NULL){
                cout << temp->data << " " ;
                temp=temp->next;
            }
            cout << " " <<endl;
        }
    }

};


int main(){

    Doubly obj;
    int option;
    int key1, k1, data1;

     do{
        cout<< "1 to appendnode()" <<endl;
        cout << "2 to prependNode()" <<endl;
        cout << "3 to insertnode()" <<endl;
        cout << "4 to deletenodebyKey()" <<endl;
        cout << "5 to updatenodebykey()" <<endl;
        cout << "6 print" <<endl;
        cout << "7 clear screen" <<endl <<endl;

        cin >> option;
        Node* n1 = new Node();
       
        switch (option)
        {
        case 0:
            break;

        case 1:
        cout << "enter key and data of the node to be appended" <<endl;
        cin >> key1;
        cin >> data1;
        n1->key=key1;
        n1->data=data1;
        obj.appendNode(n1);
        break;

        case 2:
        cout << "enter key and data of the node to be prepended" << endl;
        cin >> key1;
        cin >> data1;
        n1->key=key1;
        n1->data=data1;
        obj.prepend(n1);
        break;

        case 3:
            cout << "enter key of node after which you wish to insert new node" <<endl;
            cin >>k1;
            cout << "enter key and data of the new node" <<endl;
            cin >> key1;
            cin >> data1;
            n1->key=key1;
            n1->data=data1;
        obj.insertNode(k1,n1);
        break;

        case 4:
            cout << "enter key of the node you wish you delete" << endl;
            cin >> k1;
            obj.deleteNode(k1);
            break;
        
        case 5:
            cout << "enetr key and new data to be updated" <<endl;
            cin >> k1;
            cin >> data1;
            obj.updateNode(k1,data1);
            break;
        case 6:
        obj.printNode();
         break;

         case 7:
         system("cls");
         break;
        
        default:
            cout<< "enter proper option" << endl;
        }

    }while(option!=0);

    return 0;
}