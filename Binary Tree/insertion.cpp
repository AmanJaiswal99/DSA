#include <iostream>
#include <queue>
using namespace std;

struct Node{

    int data;
    struct Node* left;
    struct  Node* right;

};

// function to create a new node

Node* create(int data){
    Node* newNode = new Node();
    if(!newNode){
        cout << "memory error\n";
        return NULL;
    }

    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

// function to insert element in binary tree

Node* insert(Node* root, int data){
    if(root ==NULL){
        root = create(data);
        return root;
    }
    // else do level order traversal until we find an empty slot
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }
        else{
            temp->left = create(data);
            return root;
        }
        if(temp->right !=NULL){
            q.push(temp->right);

        }
        else{
            temp->right = create(data);
            return root;
        }
    }
}

//inorder traversal of binary tree

void inorder(Node* temp){
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}


int main(){

    Node* root = create(10);
    root ->left = create(11);
    root -> left -> left = create(7);
    root -> right = create(9);
    root -> right -> left = create(15);
    root -> right -> right = create(8);

    cout << " now we do inorder traversal before insertion "; 
    inorder(root);
    cout << endl;

    int key = 12;
    root = insert(root, key);

    cout << "inorder traversal after insertion ";
    inorder(root);
    cout << endl;

    return 0;
}