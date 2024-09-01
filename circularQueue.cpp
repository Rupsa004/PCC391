#include<iostream>
using namespace std;
#define MAX 5

class queue{
    private:
        int arr[MAX];
        int front;
        int rear;
    public:
        queue(){
            front = -1;
            rear = -1;
        }
        void isfull(){
            if (front == MAX - 1){
                cout<<"Queue is full";
                return;
            }
            else{
                cout<<"Queue is not full";
                return;
            }
        }
        void isempty(){
            if (front == -1){
                cout<<"Queue is empty";
                return;
            }
            else{
                cout<<"Queue is not empty";
                return;
            }
        }
        void enqueue(int value){
        if((rear+1)%MAX == front){
            cout<<("Queue is full");
            return;
        }
        else if(front==-1 && rear==-1){
            front=rear=0;
            arr[rear]=value;
            return;
        }
        else{
            rear=(rear+1)%MAX;
            arr[rear]=value;
            return;
        }
    }
        void dequeue(){
        if(front==-1 && rear==-1){
            cout<<("Queue is empty");
            return;
        }
        else if(front==rear){
            front=-1;
            rear=-1;
            return;
        }
        front=(front+1)%MAX;
        return;
    }
        void display(){
            if(rear == -1 && front==-1){
                cout<<"Queue is empty";
                return;
            }
            int i = front;
            while(i != rear){
                cout<<arr[i]<<" ";
                i = (i+1)%MAX;
            }
            cout<<arr[i];
        }
};

int main(){
    queue q;
    int choice,value;

    do{
        cout<<"\nMenu\n";
        cout<<"1.)Is Full\n";
        cout<<"2.)Is Empty\n";
        cout<<"3.)Insert element\n";
        cout<<"4.)Delete element\n";
        cout<<"5.)Display\n";
        cout<<"0.)Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
                q.isfull();
                break;
            case 2:
                q.isempty();
                break;
            case 3:
                cout<<"Enter element to insert:";
                cin>>value;
                q.enqueue(value);
                break;
            case 4:
                q.dequeue();
                break;
            case 5:
                q.display();
                break;
            case 0:
                cout<<"Exiting...";
                break;
            default:
                cout<<"Invalid choice";
                break;
        }
    }
    while(choice != 0);
    return 0;
}