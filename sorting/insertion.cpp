#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){

    int j=0;
    int key = 0;

    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }

}

int main(){

    int arr[5];
    cout << "enter 5 elements in random order" << endl;
    for(int i=0;i<5;i++){
        cin >> arr[i];
    }

    insertionSort(arr,5);

    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }

    return 0;
}