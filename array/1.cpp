// Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements. 


#include <iostream>
#include <vector>
using namespace std;

void rotate(int ar[],int d,int n){
    vector<int> arr;
    
    for(int i=d;i<n;i++){
        arr.push_back(ar[i]);
    }
    for(int i=0;i<d;i++){
        arr.push_back(ar[i]);
    }
    for(auto item: arr){
        cout << item;
    }


}


int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d=2;
    int n = 7;
    rotate(arr,d,n);
    return 0;
}