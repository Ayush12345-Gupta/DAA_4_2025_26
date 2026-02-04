#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};
void insert(Node* &head,int val)
{
    Node* newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void deletevalue(Node* &head,int val)
{
    if(head==NULL)
    {
        cout<<"List is empty";
        return;
    }
    Node* temp=head;
    if(temp->data==val)
    {
        head=temp->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        delete temp;
        return;
    }
    while(temp!=NULL&&temp->data!=val)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return;
    }
    if(temp->next!=NULL)
    {
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL)
    {
        temp->prev->next=temp->next;
    }
    delete temp;
}
void disp(Node* head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* head=NULL;
    insert(head,60);
    insert(head,30);
    insert(head,20);
    disp(head);
    deletevalue(head,30);
    disp(head);
    return 0;
}