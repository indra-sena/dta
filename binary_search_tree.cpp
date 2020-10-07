#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
  int value;
  struct Node *left,*right;
};

struct Node* newNode(int v){
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp->value = v;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct Node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->value << " -> ";
    inorder(root->right);
  }
}

struct Node* insert(struct Node *root, int val){
  if(root == NULL){
    return newNode(val);
  }
  if(val < root->value){
    root->left = insert(root->left,val);
  }
  else{
    root->right = insert(root->right,val);
  }
  return root;
}

struct Node* getMinimum(struct Node *root){
  if(root == NULL){
    return NULL;
  }
  if(root->left == NULL){
    return root;
  }
  else{
    return getMinimum(root->left);
  }
}

struct Node* remove(struct Node *root, int key){
  if(root==NULL) return NULL;

  if(root->value > key){
    root->left = remove(root->left,key);
  }
  else if(root->value < key){
    root->right = remove(root->right,key);
  }
  else{
    if(root->left == NULL){
      struct Node *temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      struct Node *temp = root->left;
      free(root);
      return temp;
    }
    struct Node *temp = getMinimum(root->right);
    root->value = temp->value;
    root->right = remove(root->right,temp->value);
  }
  return root;
}

int main(){
  struct Node *root = NULL;
  root = insert(root,3);
  root = insert(root,2);
  root = insert(root,5);
  root = remove(root,2);
  inorder(root);
  return 0;
}
