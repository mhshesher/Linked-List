#include<bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head=NULL;

void display(){
    Node* n=head;
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
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
    new_node->next=head;
    head=new_node;
}

void insertEnd(int data){

    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=NULL;

    Node* temp=head;

    if(temp==NULL){
        head=new_node;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=new_node;
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
            temp->next=new_node;
            break;
        }
        temp=temp->next;
        ct++;
    }
}

void deleteByValue(int data){

    Node* temp=head;
    Node* prev=(Node*)malloc(sizeof(Node));
    while(temp!=NULL){
        if(temp->data==data){
            prev->next=temp->next;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    cout<<"data not found"<<endl;
}

void deleteByPosition(int pos){

    Node* temp=head;
    Node* prev=(Node*)malloc(sizeof(Node));
    int ct=1;
    while(temp!=NULL){
        if(ct==pos){
            prev->next=temp->next;
            return;
        }
        prev=temp;
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

