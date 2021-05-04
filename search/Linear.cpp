#include <iostream>
using namespace std;

void linearSearch(int a[],int n,int l){
    // searchers all the elements
    int temp=NULL;
    for(int i=0;i<l;i++){
        if(a[i]==n){
            temp=i;
        }
    }
    if(temp==NULL){
        cout << "no such element in the array" <<endl;
    }else{
        cout << "element present at index " << temp << endl;
    }
}





int main(){
    
    int arr[9]={1,5,6,23,45,46,56,65,78};
    cout<<"Enter an element to search" <<endl;
    int num;
    cin >> num;
    linearSearch(arr,num,9);

    return 0;
}