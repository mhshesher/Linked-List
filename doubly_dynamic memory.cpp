#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head=NULL;

void display(){

    cout<<"Normal Order: ";
    Node* temp1=head;
    while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<endl;

    cout<<"Reverse Order: ";
    Node* temp2=head;
    while(temp2->next!=NULL) temp2=temp2->next;

    while(temp2!=NULL){
        cout<<temp2->data<<" ";
        temp2=temp2->prev;
    }
    cout<<endl;
}

int len(){

    Node* temp=head;
    int ct=0;
    while(temp!=NULL){
        temp=temp->next;
        ct++;
    }

    return ct;
}

void insertFront(int data){

    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

void insertEnd(int data){

    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;

    Node* temp=head;

    if(temp==NULL){
        head=new_node;
        return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=new_node;
    new_node->prev=temp;
    new_node->next=NULL;
}

void insertAny(int data, int pos){

    if(pos==0){
        insertFront(data);
        return;
    }
    if(pos==len()+1){
        insertEnd(data);
        return;
    }
    if(pos>len()+1){
        cout<<"invalid position"<<endl;
        return;
    }

    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;

    Node* temp=head;
    int ct=1;
    while(temp->next!=NULL){
        if(ct==pos-1){
            new_node->next=temp->next;
            temp->next->prev=new_node;
            temp->next=new_node;
            new_node->prev=temp;
            return;
        }
        temp=temp->next;
        ct++;
    }
}

void deleteByValue(int data){

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==data){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            return;
        }
        temp=temp->next;
    }
    cout<<"data not found"<<endl;
}

void deleteByPosition(int pos){

    Node* temp=head;
    int ct=1;
    while(temp!=NULL){
        if(ct==pos){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            return;
        }
        temp=temp->next;
        ct++;
    }
    cout<<"position not found"<<endl;
}

int main(){

    int x, n;

    cout<<"Number of elements in linked list ";
    cin>>n;
    cout<<"Elements of the linked list ";
    for(int i=0;i<n;i++){
        cin>>x;
        insertEnd(x);
        display();
    }

    cout<<"To insert at any position, enter the value and the position: ";
    int val, pos;
    cin>>val>>pos;
    insertAny(val,pos);
    display();
    cout<<"To insert in front, enter the value ";
    cin>>x;
    insertFront(x);
    display();
    cout<<"To delete by value, enter the value ";
    cin>>x;
    deleteByValue(x);
    display();
    cout<<"To delete by position, enter the position ";
    cin>>x;
    deleteByPosition(x);
    display();

    return 0;
}

