#include<iostream>
using namespace std;
#define MAXSIZE 100

class stack{
    private:
        int arr[MAXSIZE];
        int top;

    public:
      stack();
        void push(int);
        int pop();
        bool isEmpty();
        bool isFull();
        int peek();
        void display();
       
    };
    stack::stack(){
        top=-1;
    }

    void stack ::push(int element){
       if(isFull()){
            cout<<"stack is full"<<endl;
            return;
        }
        else{
            top++;
            arr[top]=element;
            cout<<"stack inserted"<<endl;
            
        }

    }
    int stack:: pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        else{
            int x=arr[top--];
            return x;
        }

    }
    bool stack::isEmpty(){
        if(top==-1)
            return true;
        else
            return false;

    }
    bool stack::isFull(){
        if(top==MAXSIZE-1)
            return true;
        else
            return false;

    }
    int stack:: peek(){
        if(!isEmpty())
            return arr[top];
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }

    }
    void stack::display(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
        }
        else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
        }

    }



int main(){
    stack s;
    int ch;

    while(1){
        cout<<"1.Push"<<endl
            <<"2.Pop"<<endl
            <<"3.Is it Empty"<<endl
            <<"4.Is it Full"<<endl
            <<"5.Peek"<<endl
            <<"6.display"<<endl
            <<"7.exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                int data;
                cout<<"Enter Value"<<endl;
                cin>>data;
                s.push(data);
                break;
            case 2:
                cout<<s.pop()<<endl;
                break;
            case 3:
                cout<<s.isEmpty()<<endl;
                break;
            case 4:
                cout<<s.isFull()<<endl;
                break;
            case 5:
                cout<<s.peek()<<endl;
                break;
            case 6:
                s.display();
                break;

            case 7:
                exit(0);
                break;
            default:
                cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
