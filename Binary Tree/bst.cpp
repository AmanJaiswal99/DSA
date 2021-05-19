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

    void insertNode(TreeNode *new_node){ // insert a node
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

    void printPreorder(TreeNode* r){ // ROOT LEFT RIGHT
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

    void printInOrder(TreeNode *r){ //LEFT ROOT RIGHT
        if(r==NULL){
            return;
        }
        //recur to left
        printInOrder(r->left);
        //print value
        cout << r->value <<" ";
        // then recur to right
        printInOrder(r->right);
    }

    void printPostOrder(TreeNode *r){ //LEFT RIGHT ROOT
        if(r==NULL){
            return;
        }
        //recur to left
        printPostOrder(r->left);

        // recur to right
        printPostOrder(r->right);

        //print value
        cout << r->value << " ";
    }

    TreeNode *IterativeSearch(int v){ // checks if node is present
        if(root==NULL){
            return root;
        }else{
            TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
        return NULL;
        }
    }

    int height(TreeNode *r){
        if(r==NULL){
            return -1;
        }else{
           int leftHeight = height(r->left);
           int rightHeight = height(r->right);
           if (leftHeight>rightHeight){
               return leftHeight+1;
           }else{
               return rightHeight+1;
           }
        }
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
        cout << "5 height of tree " <<endl;
        cout << "6 clear screen " << endl;
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
             
            cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
            cin >> val;
            new_node=obj.IterativeSearch(val);
            if(new_node!=NULL){
                cout << " value exists " << endl;
            }else{
                cout << " value not found " <<endl;
            }
            break;

            case 3:
            // delete node
            break;

            case 4:
            // print node
            cout << "Preorder: ";
            obj.printPreorder(obj.root);
            cout << endl;

            cout << "InOrder: ";
            obj.printInOrder(obj.root);
            cout << endl;

            cout << "PostOrder: ";
            obj.printPostOrder(obj.root);
            cout << endl;
            break;

            case 5:
            int height =obj.height(obj.root);
            cout << "the height is: " << height <<endl;
            break;

            case 6:
            system("cls");
            break;

            default:
            cout << "enter proper option number" << endl; 
        }

    }while(option!=0);

    return 0;
}