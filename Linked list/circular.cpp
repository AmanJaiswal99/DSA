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

class CircularLinkedList{
    public:
    Node* head;

    CircularLinkedList(){
        head = NULL;
    }
    CircularLinkedList(Node *n){
        head=n;
    }
    //check if node exists using key value
    Node* nodeExist(int k){
        Node* temp = NULL;
        Node* ptr = head;

        if(ptr==NULL){
            return temp;
        }else{
            do{
                if(ptr->key==k){
                    temp=ptr;
                }
                ptr=ptr->next;
            }while(ptr!=head);
            return temp; 
        }
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
                while(ptr->next!=head){
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->next=head;
                 cout << "node appended" << endl;
            }
        }
    };

    //prepend node- Attach a node to the start

    void prepend(Node *n){
        if(nodeExist(n->key)!=NULL){
            cout <<"node already exist with that value" <<endl;
        }else{
            Node *ptr=head;
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=n;
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
            if(ptr->next==head){
                n->next=head;
                ptr->next=n;
                cout << "node inserted" <<endl;
            }else{
            n->next=ptr->next;
            ptr->next=n;
            cout << "node inserted" <<endl;
            }
        }
        }
    }

    //delete node by unique key
    void deleteNode(int k){
       Node *ptr = nodeExist(k);
       if(ptr==NULL){
           cout << "node doesnt exist" <<endl;
       }
       else if(ptr==head){
           if(head->next==NULL){
               head=NULL;
               cout << "node deleted" <<endl;
           }else{
               Node *ptr1=head;
               while(ptr1->next!=head){
                   ptr1=ptr1->next;
               }
               ptr1->next=head->next;
               head=head->next;
           }
       }else{
           Node *temp=NULL;
           Node *prev=head;
           Node *current=head;
           while(current!=NULL){
               if(current->key==k){
                   temp=current;
                   current=NULL;
               }else{
                   prev=prev->next;
                   current=current->next;
               }
           }
           prev->next=temp->next;
           cout << "node deleted" <<endl;
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
            do{
                cout << temp->data << endl;
                temp=temp->next;
            }while(temp!=head);
        
            
        }
    }
};
 



int main(){

    CircularLinkedList s;
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