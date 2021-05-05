#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){

        for(int i=0;i<n-1;i++){
            int min=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[min]){
                   min = j;
                }
            }
            if(min!=i){
                int temp = arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
            }
        }
}

int main(){
    int arr[5];
    cout << "enter 5 elements in random order" << endl;
    for(int i=0;i<5;i++){
        cin >> arr[i];
    }

    selectionSort(arr,5);

    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }

    return 0;
}