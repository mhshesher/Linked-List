#include<bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head=(Node*)malloc(sizeof(Node));

void display(){
    Node* n=head;
    bool flag=0;
    while(n!=NULL){
        if(n==head){
            if(!flag) flag=1;
            else break;
        }
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}

void insertFront(int data){

    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }

    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=head;
    temp->next=new_node;
    head=new_node;
}

void insertAny(int data, int pos){

    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;

    Node* prev=(Node*)malloc(sizeof(Node));
    Node* temp=head;
    int ct=1;
    while(temp->next!=head){
        if(ct==pos-1){
            new_node->next=temp->next;
            temp->next=new_node;
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

    Node* first = NULL;
    Node* second = NULL;
    Node* third = NULL;

    first=(Node*)malloc(sizeof(Node));
    second=(Node*)malloc(sizeof(Node));
    third=(Node*)malloc(sizeof(Node));

    head=first;

    first->data=1;
    first->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=first;

    display();
    insertFront(9);
    display();
    insertAny(13,3);
    display();
    deleteByValue(3);
    display();
    deleteByPosition(2);
    display();

    return 0;
}

