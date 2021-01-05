#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

int main(){

    //malloc() reserves a block of memory of the specific number of bytes and returns a pointer that can be casted into any type.
    Node* first=(Node*)malloc(sizeof(Node));
    //here (Node*) means we want pointer to be Node class type;
    //here sizeof() returns the size of each value of given data type;
    cout<<first->data<<endl;
    cout<<first<<endl;

    //calloc() works same a malloc() but it initializes all the bits by zero, where malloc() don't do that, malloc() only allocates the memory.
    Node *second=(Node*)calloc(1,sizeof(Node));
    cout<<second->data<<endl;
    cout<<second<<endl;

    //allocating malloc() and calloc() doesn't set the memory free automatically. for this we use free()
    free(first);

    return 0;

}
