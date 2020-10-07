#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
  int value;
  struct Node * left, *right;
  Node(int n){
    value = n;
    left = right = NULL;
  }
};

void inOrder(struct Node *node){
  if(node == NULL) return;
  //left->node->right
  inOrder(node->left);
  cout<<node->value<<" ";
  inOrder(node->right);
}

void preOrder(struct Node *node){
  if(node == NULL) return;
  // node->left->right;
  cout<<node->value<<" ";
  preOrder(node->left);
  preOrder(node->right);
}

void postOrder(struct Node *node){
  if(node == NULL) return;
  //left->right->node
  postOrder(node->left);
  postOrder(node->right);
  cout<<node->value<<" ";
}

int main(){
  struct Node * root;
  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  cout<<"InOrder : ";
  inOrder(root);
  cout<<endl;
  cout<<"preOrder : ";
  preOrder(root);
  cout<<endl;
  cout<<"postOrder : ";
  postOrder(root);
  cout<<endl;
  return 0;
}
