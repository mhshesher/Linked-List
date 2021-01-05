#include<bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

int main(){

   Node* first = NULL;
   Node* second = NULL;
   Node* third = NULL;

   first=new Node();
   second=new Node();
   third=new Node();


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
