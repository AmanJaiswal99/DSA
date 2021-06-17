#include <iostream>
using namespace std;

struct Trie{
    struct Trie *children[26];
    bool endOfWord;
};

struct Trie *getNode(void){
        struct Trie *pnode = new Trie;
        pnode->endOfWord=false;
        for(int i=0;i<26;i++){
            pnode->children[i]=NULL;
        }
        return pnode;
}

void insert(struct Trie *root, string s){
    struct Trie *p=root;
    int n=s.length();
    for(int i=0;i<n;i++){
        int k=s[i]-'a'; // gives the index of the character
        if(!p->children[k]){
            p->children[k]=getNode();
        }
        p=p->children[k];
    }
    p->endOfWord=true;
}

bool search(struct Trie *root,string s){
    struct Trie *p=root;
    int n=s.length();
    for(int i=0;i<n;i++){
        int k=s[i]-'a';
        if(p->children[k]==NULL){
            return false;
        }
        p=p->children[k];
    }
    return (p->endOfWord && p!=NULL);
}


int main(){

    struct Trie *root=getNode();
     insert(root,"abc");
    insert(root,"abcde");
    cout << search(root,"abc") <<endl; // returns 1
    cout << search(root,"abcdef") <<endl; //returns 0

    return 0;
}
