#include <iostream>
using namespace std;
#define SPACE 10

class TreeNode{
    public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        value=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int v){
        value=v;
        left = NULL;
        right = NULL;
    }
};

 class BST{

     public:
     TreeNode *root;
    BST(){
        root=NULL;
    }

     bool isEMpty(){ // check if tree is empty
         if(root==NULL){
             return true;
         }else{
             return false;
         }
     }

    void insertNode(TreeNode *new_node){
        if(root==NULL){
            root=new_node;
            cout << "value inserted as root node" << endl;
        }else{
            TreeNode *temp =root;
            while(temp!=NULL){
                if(new_node->value==temp->value){
                    cout << "value already exists, try a different value";
                    return;
                }
                else if((new_node->value<temp->value) && (temp->left==NULL)){
                    temp->left=new_node;
                    cout << "value inserted to the left" << endl;
                    break;
                }else if(new_node->value<temp->value){
                    temp=temp->left;
                }
                 else if((new_node->value>temp->value) && (temp->right==NULL)){
                    temp->right=new_node;
                    cout << "value inserted to the right" << endl;
                    break;
                }else{
                    temp=temp->right;
                }
            }
        }
    }

    void printPreorder(TreeNode* r){
        if(r==NULL){
            return;
        }
        // first print node
        cout << r->value << " ";
        // then recur on left subtree
        printPreorder(r->left);
        // then recur on right subtree
        printPreorder(r->right);
    }

 };

int main(){
    BST obj;
    int option,val;

    do{
        cout << "1 insert node " << endl;
        cout << "2 search node " << endl;
        cout << "3 delete node " <<endl;
        cout << "4 print bst values " <<endl;
        cout << "5 clear screen " << endl;
        cout << "0 exit program " <<endl;

        cin >> option;

        TreeNode *new_node = new TreeNode();

        switch(option){
            case 0:
            break;
            
            case 1:
            // insert node
            cout << "enter the value of tree node to insert in BST: ";
            cin >> val;
            new_node -> value=val;
            obj.insertNode(new_node);
           
            break;
            
            case 2:
            // search node
            break;

            case 3:
            // delete node
            break;

            case 4:
            // print node
            cout << "Preorder: ";
            obj.printPreorder(obj.root);
            cout << endl;
            break;

            case 5:
            system("cls");
            break;

            default:
            cout << "enter proper option number" << endl; 
        }

    }while(option!=0);

    return 0;
}