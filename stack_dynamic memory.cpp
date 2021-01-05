#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *top=NULL;

int len(){

    Node* temp=top;
    int ct=0;
    while(temp!=NULL){
        temp=temp->next;
        ct++;
    }

    return ct;
}

void display(){

    if(top==NULL){
        cout<<"empty stack"<<endl;
        return;
    }

    Node* n=top;
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}

void push(int data){

    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=NULL;

    if(top==NULL){
        top=new_node;
        return;
    }

    Node* temp=top;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=new_node;
}

void pop(){

    if(len()==0){
        cout<<"empty stack"<<endl;
        return;
    }
    if(len()==1){
        top=NULL;
        return;
    }

    Node* temp=top;
    Node* prev=NULL;

    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }

    prev->next=NULL;
    free(temp);

}

int main(){

    int n, x;

    cout<<"Numbers of operations ";

    cin>>n;
    for(int i=0;i<n;i++){
        if(i%3==0){
            pop();
        }
        else{
            cout<<"Enter the value to push ";
            cin>>x;
            push(x);
        }
        display();
    }

    return 0;
}

