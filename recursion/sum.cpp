#include <iostream>
using namespace std;

//sum of first n numbers

int sum(int n){
    if(n!=0){
        
        return (n + sum(n-1));
    }else{
        
        return n;
    }
}


int main(){

    cout << sum(5);
    return 0;
}