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
            cout << "node inserted" <<endl;
        }
        }
    }

    //delete node by unique key
    void deleteNode(int k){
        if(head==NULL){
            cout<<"linked list in already empty" <<endl;
        }
        else if(head!=NULL){
            if(head->key==k){
                head = head->next;
                cout <<"node removed" <<endl;
            }else{
                Node* temp=NULL;
                Node* prev = head;
                Node* current = head->next;
                while(current!=NULL){
                  if(current->key==k){
                      temp=current;
                      current=NULL;
                  }else{
                      prev=prev->next;
                      current=current->next;
                  }
                }
                if(temp!=NULL){
                    prev->next=temp->next;
                    cout <<"node unlinked" <<endl;
                }else{
                    cout <<"node doesn't exist with key value" <<endl;
                }
            }
        }
    }

    //update node
    void updateNodeByKey(int k, int d){
        Node* ptr = nodeExist(k);
        if(ptr!=NULL){
            ptr->data=d;
            cout << "node updated" <<endl;
        }else{
            cout << "node doesnt exist with that key value" <<endl;
        }
    }

    //printing
    void printList(){
        if(head==NULL){
            cout << "NOTHING TO DISPLAY" <<endl;
        }else{
            Node* temp = head;
            while(temp!=NULL){
                cout << temp->data << endl;
                temp=temp->next;
            }
            
        }
    }
};
 



int main(){

    SinglyLinkedList s;
    int option;
    int key1,k1,data1;
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
        s.appendNode(n1);
        break;

        case 2:
        cout << "enter key and data of the node to be prepended" << endl;
        cin >> key1;
        cin >> data1;
        n1->key=key1;
        n1->data=data1;
        s.prepend(n1);
        break;

        case 3:
            cout << "enter key of node after which you wish to insert new node" <<endl;
            cin >>k1;
            cout << "enter key and data of the new node" <<endl;
            cin >> key1;
            cin >> data1;
            n1->key=key1;
            n1->data=data1;
        s.insertNodeAfter(k1,n1);
        break;

        case 4:
            cout << "enter key of the node you wish you delete" << endl;
            cin >> k1;
            s.deleteNode(k1);
            break;
        
        case 5:
            cout << "enetr key and new data to be updated" <<endl;
            cin >> k1;
            cin >> data1;
            s.updateNodeByKey(k1,data1);
            break;
        case 6:
        s.printList();
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