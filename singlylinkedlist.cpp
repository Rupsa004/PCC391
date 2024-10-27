#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
class linkedlist
{
private:
    Node *head;
public:
    linkedlist(){
        head=NULL;
    
}
~linkedlist()
{
    while (head!=NULL){
        Node *temp=head;
        head=head->next;
        delete(temp);
    }    
}
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void deleteFromBeginning();
    void deleteFromEnd();
    void display();
    bool search(int value);
    void reverse();
    void deleteItem(int);

};
void linkedlist::insertAtBeginning(int value){
    Node *newNode= new Node(value);  // Create a new node with the given value
    newNode->next=head; // Set the new node's next to the current head
    head=newNode;       // Update the head to point to the new node
    cout<<"Inserted "<<value<<" at the beginning"<<endl;
}
void linkedlist::insertAtEnd(int value){
    Node *newNode= new Node(value);
    if(!head){
        head=newNode;   // If the list is empty, set head to the new node
    }
    else{
        Node *current=head; // Start from the head
        while (current->next)  // Traverse to the end of the list 
        {
            current=current->next;
        current->next=newNode;  // Set the last node's next to the new node
        }   
    }
    cout<<"Inserted "<<value<<" at end"<<endl;
}
void linkedlist::deleteFromBeginning(){
    if(!head){
        cout<<"list is empty"<<endl;
        return;
    }
    else{
        Node *temp=head;   // Store the current head node in temp
        head=head->next;   // Move the head pointer to the next node
        delete temp;       // Delete the old head node to free memory
        cout<<"Deleted from the beginning"<<endl;
    }
}
void linkedlist::deleteFromEnd(){
    if(!head){
        cout<<"list is empty"<<endl;
        return;
    }
    if(head->next==NULL){   // Check if there is only one node
        delete head;    // Delete the only node in the list
        head=NULL;      //empty
        cout<<"Deleted from end"<<endl;
        return;
    }
    // current is a temporary pointer used for navigating through the linked list to find and manipulate nodes without altering the actual structure of the list.
    Node *current=head; // Start from the head 
    while (current->next->next!=NULL)   // Traverse to the second last node
        current=current->next; //move to the next
    delete current->next;   //delete last node
    current->next=NULL; // Set the second last node's next to NULL
    cout<<"Deleted from end"<<endl;   
}
void linkedlist::display(){
    if(head==NULL){
        cout<<"list is empty"<<endl;
        return;  
    }
    Node *temp=head;    // Start from the head of the list
    while(temp!=NULL){  // Traverse until the end of the list
        cout<<temp->data<<" ";  // Print the data of the current node
        temp=temp->next;    //move to the next node
    }
    cout<<endl; // Print a newline after displaying all elements

}
bool linkedlist::search(int value){
    Node *current=head;
    while(current!=NULL){   // Continue until the end of the list
        if(current->data==value)    //check current node's data matches the search
            return true;
        current=current->next;//move to next node
    }
    return false;
}
void linkedlist::reverse(){
    Node *p=head;   // Initialize p to the head of the list
    Node *q;        // Temporarily hold the current node
    Node *r=NULL;  // The new next pointer for the reversed list  
    
    while(p!=NULL){ //loop untill NULL comes
        q=p;        // Store the current node in q
        p=p->next;  // Move p to the next node
        q->next=r;  // Reverse the current node's next pointer to point to the previous node
        r=q;    // Move r to the current node
    }
    head=q; //end the loop
}
void linkedlist::deleteItem(int value){
    if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  // Check if the node to delete is the head
  if(head->data==value){
    Node *temp=head;    // Store the current head node in temp
    head=head->next;    // Update head to the next node
    delete temp;        //delete the old head node
    return;
  }
  Node *current=head;   // Start from the head //traverse the list to find node to delete
  while(current->next!=NULL){
    if(current->next->data==value){  // Check if the next node contains the value
      Node *temp=current->next; // Store the node to delete in temp
      current->next=current->next->next; //node to delete
      delete temp;  //deleted node
      return;
    }
    current=current->next; //move to next node
  }
}



int main(){
    linkedlist list;
    int ch,data;

    do{
        cout<<"1.Insert at beginning"<<endl;
        cout<<"2.Insert at end"<<endl;
        cout<<"3.Delete from beginning"<<endl;
        cout<<"4.Delete from end"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Search"<<endl;
        cout<<"7.Reverse"<<endl;
        cout<<"8.Delete Item"<<endl;
        cout<<"enter choice: "<<endl;
        cin>>ch;

        switch (ch)
        {
        case 1:
        cout<<"Enter data"<<endl;
        cin>>data;
        list.insertAtBeginning(data);
        break;
        case 2:
        cout<<"Enter data"<<endl;
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
        list.display();
        break;
        case 6:
        cout<<"Enter data"<<endl;
        cin>>data;
        if(list.search(data))
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;
        break;
        case 7:
        list.reverse();
        case 8:
        cout<<"Enter data"<<endl;
        cin>>data;
        list.deleteItem(data);
        }
    }while (1);
    return 0;
    
}