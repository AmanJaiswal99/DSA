#include <iostream>
using namespace std;

int binarysearch(int arr[],int left,int right, int x){

    while(left<=right){
        int mid=(right+left)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            left=mid+1;
           
            
        } else{
            right=mid-1;
        }
    }
    return -1;
}


int main(){

    int output;
    int num;
    int arr[10];
    cout << "enter 10 numbers in ascending order" <<endl;
    for(int i=0;i<10;i++){
        cin >> arr[i];
    }

    cout << "enter the number you wish to search in the array" <<endl;
    cin >> num;

    output=binarysearch(arr,0,9,num);
    if(output==-1){
        cout << "can't find the number" <<endl;
    }else{
        cout <<"the number is present at index " << output <<endl;
    }

    
    return 0;
}