#include<iostream>
using namespace std;
 struct Node
 {
    /* data */
    int data; Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
 };
void createLL(Node *head)
{
    Node *temp=head;
    for(int i=2;i<=5;i++)
    {
        temp->next=new Node(i);
        temp=temp->next;
    }
};

void display(Node *head)
{
     Node *disp=head;
     while(disp!=0)
     { cout<<disp->data<<endl;
        disp=disp->next;

     }
};
void insertBegin(Node *head)
{
    Node *newNode = new Node(100); // creating a new node with value 100
newNode->next = head; // pointing the next pointer of new node to current head
head = newNode; // updating the head pointer to point to the new node
   display(head);

}
void insertEnd(Node *head)
{
    Node *newNode=new Node(99);
     Node*temp=head;
     while(temp->next!=NULL)
      temp=temp->next;

     temp->next=newNode;

     display(head);
}
void insertAtPosition(Node *&head){
    Node *newNode = new Node(101);

}
void deleteStart(Node* &head) {
    // Check if the list is empty
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    
    // Save the address of the first node
    Node* temp = head;
    
    // Update the head to point to the second node
    head = head->next;
    
    // Delete the first node
    delete temp;
    
    // Print the updated list
    display(head);
}
void deleteLast(Node *&head) {
    // create a temporary pointer pointing to the head node
    Node *temp = head;

    // traverse to the second last node of the linked list
    while (temp->next->next != NULL)
        temp = temp->next;

    // delete the last node of the linked list
    delete temp->next;

    // set the next pointer of the second last node to NULL to make it the new last node
    temp->next = NULL;
}
void InsertSorted(Node *&head, int x)
{
    Node *newNode=new Node(x);
  
   // if(head==NULL) head=newNode;
    if(x<head->data) {
        newNode->next=head;
        


    }  Node *temp=head;
    while(temp->next!=NULL and temp->next->data < x )
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    display(head);
}
 
int main()
{
    Node *head=new Node(1);
    createLL(head);
    // display(head);
    // insertBegin(head);
    // insertEnd(head);
    // deleteLast(head);
    InsertSorted(head,4);
    return 0;
}
 
 