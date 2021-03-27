#include <iostream>
using namespace std;
#include <queue>

struct Node{
    int data;
    struct Node *left, *right;
};

// function to create a new node of tree and return pointer

struct Node *newNode(int data){
    struct Node* temp = new Node;
    temp->data = data;
    temp -> left = temp -> right = NULL;
}

// inorder traversal of a binary tree (Left, Root, Right)
void inorder(struct Node* temp){
    if(!temp){
        return;
    }
    inorder(temp->left);
    cout << temp -> data << " ";
    inorder(temp-> right);
}

// function to delete the given deepest node in binary tree

void deleteDeepest(struct Node* root, struct Node* d_node){
    queue<struct Node*> q;
    q.push(root);

    // do level order traversal until last node
    struct Node* temp;
    while (!q.empty()){
        temp = q.front();
        q.pop();
        if(temp == d_node){
            temp = NULL;
            delete (d_node);
            return;
        }
        if(temp -> right){
            if (temp-> right == d_node){
                temp -> right = NULL;
                delete (d_node);
                return;
            }
            else{
                q.push(temp->right);
            }

        }

        if(temp->left){
            if(temp -> left == d_node){
                temp -> left = NULL;
                delete (d_node);
                return;
            }
            else{
                q.push(temp->left);
            }
        }

    }
}

// function to delete element in binary tree

Node* deletion(struct Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root -> left == NULL && root-> right == NULL){
        if(root -> data == key){
            return NULL;
        }
        else{
            return root;
        }
    }
    queue<struct Node*> q;
    q.push(root);

    struct Node* temp;
    struct Node* key_node = NULL;

    // do level order traversal to find deepest node(temp) and node to be deleted (key_node)
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp -> data == key){
            key_node = temp;
        }

        if(temp-> left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    if(key_node!=NULL){
        int x = temp-> data;
        deleteDeepest(root, temp);
        key_node->data = x;
    }
    return root;
}


int main(){

        struct Node * root = newNode(10);
        root -> left = newNode(11);
        root->left->left = newNode(7);
        root->left->right = newNode(12);
        root->right = newNode(9);
        root->right->left = newNode(15);
        root->right->right = newNode(8);

        cout << "inorder traversak before deletion: ";
        inorder(root);

        int key = 11;
        root = deletion(root,key);

        cout << endl;
        cout << "inorder traversal after deletion: ";
        inorder(root);

    return 0;
}
