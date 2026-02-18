#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
        
    }
};
void insert(Node* &head,int val)
{
    Node* newnode=new Node(val);
    if (head == NULL) {
        head = newnode;
        return;
    }
      Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void disp(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void deletenode(Node* &head,int val)
{
    if(head==NULL)
    {
        cout<<"List is empty";
        return;
    }
    if(head->data==val)
    {
        Node* del=head;
        head=head->next;
        delete del;
    }
    Node* temp=head;
    while(temp->next!=NULL&&temp->next->data!=val)
    {
        temp=temp->next;
    }
    if(temp->next!=NULL)
    {
        Node* del=temp->next;
        temp->next=temp->next->next;
        delete del;
    }


}
int main()
{
    Node* head=NULL;
    insert( head,20);
    insert( head,60);
    insert( head,30);
    deletenode(head,20);
    disp( head);
    
    return 0;
}