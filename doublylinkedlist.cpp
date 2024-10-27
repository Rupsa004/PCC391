#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int value){ //constructor
        data=value;
        prev=NULL;
        next=NULL;
    }
};
class dlinkedlist{
    Node *head;
    public:
    dlinkedlist(){
        head=NULL:
    }
    void insertAtBeginning(int);
    void insertAtEnd(int);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteItem(int);
    void display();
};

void dlinkedlist::insertAtBeginning(int value){
    Node *curr=new Node(value); //new node object current , initialized with value
    current->data=value; //node data set to value
    current->prev=NULL; //set to NULL(this node will be first node in the list)
    current->next=head; //set to current head(making the new node point)
    if(head!=NULL){
        head->prev=current;
    }
    head=current;
    return;
}

void dlinkedlist::insertAtEnd(int value){
    Node *curr= new Node(value);
    current->data=value;
    current->next=NULL;

    if(head==NULL){     //new node becomes first node
        curr->prev=NULL;//prev set to null
        head=curr;//head update to new node
        return;
    }
    Node *temp=head; //temporary pointer is initialized to head
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=current;
    current->prev=temp;
    return;
}
void dlinkedlist::deleteFromBeginning(){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node *temp=head; //store current head node in temp
  head=head->next; //head point to the next
  if(head!=NULL){ 
    head->prev=NULL;//if head!=NULL, prev point to NULL
  }
  delete temp;//old head node delete
}
void dlinkedlist::deleteFromEnd(){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node *temp=head; //initialize temp pointer to the head
  while(temp->next!=NULL){
    temp=temp->next;
  }
  if(temp->prev!=NULL){ //After identifying the last node, the function checks if the previous node is not NULL
    temp->prev->next=NULL;
  }
  else{         //if previous node is NULL
    head=NULL;
  }
  delete temp;
}
void dlinkedlist::deleteItem(int value){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node *temp=head;
  while(temp->data!=value){   //continues until it finds a node with the specified value
    temp=temp->next;
  }
  if(temp->prev!=NULL){
    temp->prev->next=temp->next;  //temp node (the node to be deleted) has a previous node(temp->prev!=NULL), the function updates the next pointer of the previous node to skip the temp and point temp->next.
  }
  else{
    head=temp->next; //if temp is head node(temp->prev==NULL) , head to point the temp->next
  }

  if(temp->next!=NULL){   
    temp->next->prev=temp->prev;  //prev pointer of the next node to point to the temp node's previous node.
  }
  delete temp;
}
void dlinkedlist::display(){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node *temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";  //prints the data of current node
    temp=temp->next;  //update temp to point the next node
  }
  cout<<endl;
}

int main(){
    dlinkedlist list;
    int ch,data;
    do{
        cout<<"1. Insert at beginning"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Delete from beginning"<<endl;
        cout<<"4. Delete from end"<<endl;
        cout<<"5. Delete item"<<endl;
        cout<<"6. Display"<<endl;
        cout<<"enter your choice"<<endl;
        cin>>ch;
        switch(ch){
        case 1:
        cout<<"Enter data: ";
        cin>>data;
        list.insertAtBeginning(data);
        break;
        case 2:
        cout<<"Enter data: ";
        cin>>data;
        list.insertAtEnd(data);
        break;
        case 3:
        list.deleteFromBeginning();
        break;
        case 4:
        list.deleteFromEnd();
        break;
        case 5:
        cout<<"Enter data: ";
        cin>>data;
        list.deleteItem(data);
        break;
        case 6:
        list.display();
        break;
        }
    }
    while(1);
    return 0;
}


