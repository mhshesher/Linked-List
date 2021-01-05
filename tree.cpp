#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};

Node* root=NULL;

Node* insert(Node* root, int data){

    if(root==NULL){
		Node* temp=new Node();
		temp->data=data;
		temp->left=temp->right = NULL;
		root=temp;
	}
	else if(data<root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}

void preorder(Node *temp)
{
    if(temp!=NULL){
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(Node *temp)
{
    if(temp!=NULL){
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

void postorder(Node *temp)
{
    if(temp!=NULL){
        preorder(temp->left);
        preorder(temp->right);
        cout<<temp->data;
    }
}

int main() {

    int n,x;
    cout<<"Enter the number of elements ";
    cin>>n;
    for(int i=0;i<n;i++){
            cout<<"Enter a value ";
        cin>>x;
        root=insert(root, x);
    }
    cout<<"Tree in preorder ";
    preorder(root);
    cout<<endl;
    cout<<"Tree in inorder ";
    inorder(root);
    cout<<endl;
    cout<<"Tree in postorder ";
    postorder(root);
    cout<<endl;

    return 0;
}
