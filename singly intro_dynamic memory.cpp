#include<bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

int main(){

   Node* first = NULL;
   Node* second = NULL;
   Node* third = NULL;

   first=(Node*)malloc(sizeof(Node));
   second=(Node*)malloc(sizeof(Node));
   third=(Node*)malloc(sizeof(Node));


   first->data=1;
   first->next=second;

   second->data=2;
   second->next=third;

   third->data=3;
   third->next=NULL;

   cout<<first->data<<endl;

   cout<<first->next->next->data<<endl;
   cout<<first->next->next->next<<endl;
}

