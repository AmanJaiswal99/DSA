#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){ // regular

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void optimized(int arr[], int n){ // optimized bubble sort

 for(int i=0;i<n-1;i++){
     int flag=false;
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                flag=true;
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        if(flag==false){
            break;
        }
    }
}

int main(){

     int arr[5];
    cout << "enter 5 elements in random order" << endl;
    for(int i=0;i<5;i++){
        cin >> arr[i];
    }

    bubbleSort(arr,5);

    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }

    return 0;
}