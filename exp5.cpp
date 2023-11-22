#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
this->next=NULL;

    }
    ~node(){
        int value =this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }

};
void inserthead(node* &head , int d){
    node*temp=new node(d);
    temp->next=head;
    head=temp;

}
void printnode(node* &head){
    node* temp=head;
    while (temp!=NULL)
    {
       
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
void insertatpos(node* &head,int d,int pos){
    node*temp=head;
    int cnt=1;
    while (cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    node*nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
    


}
void deletenode(node * &head,int pos){
    
    if(pos==1){
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node *curr=head;
        node *prev=NULL;
        int cnt=1;
        while (cnt<pos){
              prev=curr;
              curr=curr->next;
              cnt++;
        }
        prev->next=curr->next;
        delete curr;
        
        
    }
}
void inserttail(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;

   


}
int main(int argc, char const *argv[])
{
    node *node1=new node(1);
    node *head=node1;
    node *tail=node1;
    inserttail(tail,2);
    inserttail(tail,3);
   
    printnode(head);
    return 0;
}
