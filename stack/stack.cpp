#include <iostream>
using namespace std;

class stack{
    private:
    int top;
    int arr[5];

    public:
     stack(){
         top =-1;
         for(int i=0;i<5;i++){
             arr[i]=0;
         }
     }

     bool isEmpty(){ // checks if stack in empty
         if(top==-1){
             return true;
         }else{
             return false;
         }
     }

     bool isFull(){ // checks if stack is full
         if(top==4){
             return true;
         }else{
             return false;
         }
     }
     void push(int val){ // insert element on top
         if(isFull()){
             cout << "stack overflow";
         }else{
             top++;
             arr[top]=val;
         }
     }
    int pop(){  // removes and returns the top element
        if(isEmpty()){
            cout  << "stack underflow";
        }else{
            int popvalue = arr[top];
            arr[top]=0;
            top--;
            return popvalue;
        }
   }

   int count(){ // returns no of elements in stack
       return (top+1);
   }

   int peek(int pos){   // returns item at a position
       if(isEmpty()){
           cout << "stack empty";
       }else{
           return arr[pos];
       }
   }

   void change(int pos, int val){   // change the value at pos
    arr[pos] = val;
    cout << "value changed";
   }

   void display(){  // display all the values from top
    for(int i=4;i>=0;i--){
        cout << arr[i] << " ";
    }
   }
};

int main(){
    stack s1;
    int option, position, value;

    do{
        cout << "select options, and 0 to exit" << endl;
        cout << "1 push" << endl;
        cout<< "2 Pop" << endl;
        cout << "3 isEmpty()" << endl;
        cout << "4 isFull()" << endl;
        cout << "5 peek" << endl;
        cout << "6 count()" << endl;
        cout << "7 change()" << endl;
        cout << "8 display()" << endl;
        cout << "9 clear screen" << endl;

        cin >> option;
        switch (option){
            case 0:
                break;
            case 1:
                cout << "enter a value to push in the stack" << endl;
                cin >> value;
                s1.push(value);
                break;
            case 2:
                s1.pop();
            case 3:
                if(s1.isEmpty()){
                    cout << "stack is empty" << endl;
                    break;
                }else{
                    cout << "stack is not empty" << endl;
                }
            case 4:
            if(s1.isFull()){
                cout << "stack is full" << endl;
                break;
            }else{
                cout << "stack is not full" << endl;
                break;
            }
            case 5:
                cout << "enter the position" << endl;
                cin >> position;
                cout << s1.peek(position) << endl;
                break;
            case 7:
                cout << "enter the position which you want to change" << endl;
                cin >> position;
                cout << "enter the value" << endl;
                cin >> value;
                s1.change(position,value);
                break;
            case 6:
                cout << s1.count() << endl;
                break;
            case 8:
                s1.display();
                break;
            case 9:
                system("cls");
                break;
            default:
                cout << "enter the correct option" << endl;
        }
    }while(option!=0);
    return 0;
}