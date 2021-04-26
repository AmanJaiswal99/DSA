#include <iostream>
using namespace std;

class queue{
    private:
    int front;
    int rear;
    int arr[5];

    public:
    queue(){
    rear = -1;
    front = -1;
    for(int i=0; i<5;i++){
        arr[i]=0;
    }
    }
    
    bool isEmpty(){ // checking if queue is empty
        if(front ==-1 && rear == -1){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){  // checkin gif queue is full
        if(rear == sizeof(arr)-1){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int val){
        if(isFull()){
            cout << "overflow" << endl;
        }else{
            rear++;
            arr[rear]=val;
            front=0;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout << "the queue is empty" << endl;
        }else if(front==rear){
            arr[front] =0; 
            rear=-1;
            front=-1;
        }else{
            arr[front]=0;
            front++;
        }
    }

    int count(){
        return (rear+1);
    }

    int display(){
        for(int i=0; i<=4;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){

    queue q1;
    int option, value;

    do{
        cout << "select options, and 0 to exit" << endl;
        cout << "1 enqueue" << endl;
        cout<< "2 dequeque" << endl;
        cout << "3 isEmpty()" << endl;
        cout << "4 isFull()" << endl;
        cout << "5 count()" << endl;
        cout << "6 display()" << endl;
        cout << "7 clear screen" << endl;

        cin >> option;
        switch(option){
            case 0:
            break;

            case 1:
            int value;
            cout << "enter a non zero value" << endl;
            cin  >> value;
            q1.enqueue(value);
            q1.display();
            break;

            case 2:
            q1.dequeue();
            q1.display();
            break;

            case 3:
            if(q1.isEmpty()){
                cout << "empty" << endl;
            }else{
                cout << "not empty" <<endl;
            }
         
            break;

            case 4:
            if(q1.isFull()){
                cout << "full" << endl;
            }else{
                cout << "not full" << endl;
            }
            
            break;

            case 5:
            cout << q1.count() << endl;
            break;

            case 6:
            cout << q1.display() << endl;
            break;

           case 7:
            system("cls");
            break;
        }

    }while(option!=0);

    return 0;
}