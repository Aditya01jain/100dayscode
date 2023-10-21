#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }

};
void insertathead(node* &head,int data){
    node* temp= new node(data);
    temp ->next= head;
    head= temp;

}
void insertattail(node* &tail,int data){
    node* temp= new node(data);
    tail->next=temp;
    tail= tail->next;

}
void insertatposition(node* &head,int position,int data){
    node* temp= head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    node* nodetoinsert= new node(data);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;


}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* node1= new node(10);
    node* head = node1;
    node* tail= node1;
    print(head);
    insertathead(head,12);
    print(head);
    insertattail(tail,8);
    print(head);
    insertatposition(head,2,15);
    print(head);
    return 0;
}