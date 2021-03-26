#include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main(){

    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root ->left->left = new Node(4);
    // creates a binary tree
    //              1
    //        2            3
    //    4     null  null   null
    // null null
    return 0;
}