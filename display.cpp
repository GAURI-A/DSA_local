#include<iostream>
using namespace std;
struct Node
{
    /* data */
    int data;
    Node *next;
    Node(int x){
         data=x;
         next=NULL;
    }
};

void printRecursive(Node *head){
        // Check if the head is NULL, i.e., the end of the linked list has been reached
    if (head == NULL) {
        return;
    }

    // Print the data of the current node
    cout << head->data << " ";

    // Move to the next node by updating the head pointer
    head = head->next;

    // Recursively call the function with the updated head pointer
    printRecursive(head);

}
int main()
{
    Node *head= new Node(10); // creating new node with val 10 and storing addr in head
      Node *temp =new Node(11);
      head ->next =temp;  //linking teemp to head 
    for (int i = 0; i < 10; i++)
    {
        /* code */
       
         temp->next=new Node(i); // creating new node with val i and storing new nodes addr in next of temp
         temp=temp->next;  //  updating temp to next temp

    }
    temp=head; // we should not chnge the head pointer thus assigning addr of head to temp
    // while(temp!=NULL)  // traversing till temp becomes null
    // {
    //      cout << temp->data << "\n"; // print the value of the current node
    // temp = temp->next; // move to the next node in the linked list
    // }

    printRecursive(head);
    
return 0;
}